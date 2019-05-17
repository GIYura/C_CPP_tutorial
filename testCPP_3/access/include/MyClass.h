#ifndef MYCLASS_H
#define MYCLASS_H

namespace myClass{

    class MyClass
    {
        public:
            MyClass();
            virtual ~MyClass();

            int b;
            void setab(int);
            int geta(void);
            void reset(void);

        protected:

        private:
            int a;
    };
}


#endif // MYCLASS_H
