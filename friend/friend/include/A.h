#ifndef A_H
#define A_H


class A
{
    public:
        A();
        virtual ~A();

        void sendData(void);
        void getDat(void);

        friend void fun(A*);

    protected:

    private:
        int chNumber;
};

#endif // A_H
