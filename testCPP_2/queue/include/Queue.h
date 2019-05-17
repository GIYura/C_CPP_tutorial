#ifndef QUEUE_H
#define QUEUE_H



namespace Buffer{

    class Queue
    {
        public:
            Queue();
            virtual ~Queue();

            void init();
            void putQueue(int);
            int getQueue(void);

        protected:

        private:
            int q[100];
            int tail, head;
    };
}
#endif // QUEUE_H
