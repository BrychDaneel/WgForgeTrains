import logging
import asyncore
import socket
import struct
import json
import world

logging.basicConfig(level=logging.DEBUG, format="%(created)-15s %(msecs)d %(levelname)8s %(thread)d %(name)s %(message)s")
log = logging.getLogger(__name__)



SIZE = 8

class TestTrainHandler(asyncore.dispatcher):
    def __init__(self, conn_sock, client_address, server, world):
        self.world = world
        self.server = server
        self.client_address = client_address
        self.buffer = ""
        self.is_writable = False
        asyncore.dispatcher.__init__(self, conn_sock)
        log.debug("created Handler")

    def readable(self):
        return True


    def writable(self):
        return self.is_writable

    def handle_read(self):
        log.debug("handle read")
        data = self.recv(SIZE)
        if not data:
            log.debug("got null data")
            return
        command, size = struct.unpack("<2L",data)
        log.debug("command - %d  size - %d" % (command, size))

        data = self.recv(size)
        data = data.decode()
        log.debug("data - %s"%(data))
        self.send(self.world.make_command(command, data, self.client_address))

    def handle_write(self):
        log.debug("handle_write")
        if self.buffer:
            sent = self.send(self.buffer)
            log.debug("sent data")
            self.buffer = self.buffer[sent:]
        else:
            log.debug("nothing to send")
        if len(self.buffer) == 0:
            self.is_writable = False


    def handle_close(self):
        log.debug("handle_close")
        log.info("connection closed, client_address=%s:%s" % \
                     (self.client_address[0],
                      self.client_address[1]))
        self.close()


class TestTrainServer(asyncore.dispatcher):

    request_queue_size = 5
    address_family = socket.AF_INET
    socket_type = socket.SOCK_STREAM
    def __init__(self, address, handlerClass=TestTrainHandler):
        self.address = address
        self.handlerClass = handlerClass
        asyncore.dispatcher.__init__(self)
        self.create_socket(self.address_family, self.socket_type)
        self.server_bind()
        self.server_activate()
        self.myworld = world.World()


    def server_bind(self):
        self.bind(self.address)
        log.debug("bind address=%s:%s" % (self.address[0], self.address[1]))


    def server_activate(self):
        self.listen(self.request_queue_size)
        log.debug("listen %d" % self.request_queue_size)


    def start_server(self):
        asyncore.loop()

    def handle_accept(self):
        (conn_sock, client_address) = self.accept()
        if self.verify_request(conn_sock, client_address):
            self.process_request(conn_sock, client_address)


    def verify_request(self, conn_sock, client_address):
        return True


    def process_request(self, conn_sock, client_address):
        log.info("connaction made, client address=%s:%s" % (client_address[0],
                                                            client_address[1]))
        self.handlerClass(conn_sock, client_address, self, self.myworld)


    def handle_close(self):
        self.close()



server = TestTrainServer(("",30001))
server.start_server()
