#ifndef __SOURCE__
#define __SOURCE__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class������
    /////////////////////////////////////////////////////////////////////////////
    class Source
    {
    public:
        Source();
        void Initialize();
        void setNum(int n);
        int getNum();
        void consume();
        void add();
    private:
        int num;
    };
}
#endif