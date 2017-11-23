#pragma once
#ifndef _TIGER_TRAINS_MODELS_LINE_MODEL_H_
#define _TIGER_TRAINS_MODELS_LINE_MODEL_H_


namespace tiger{
namespace trains{
namespace models{

    class LineModel{
        private:
            const int idx;
            const int length;
            const int startPoint;
            const int endPoint;
        public:
            LineModel(const int idx, const int length, const int startPoint, const int endPoint);
            const int getIdx() const;
            const int getLength() const;
            const int getStartPoint() const;
            const int getEndPoint() const;
    };
}
}
}



#endif
