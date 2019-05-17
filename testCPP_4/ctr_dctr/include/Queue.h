#ifndef QUEUE_H
#define QUEUE_H

namespace Buffer{
    class Queue
    {
        public:
            Queue();
            virtual ~Queue();
            void putQueue(int);
            int getQueue();

        protected:

        private:
            int q[100];
            int head, tail;
    };
}
#endif // QUEUE_H
