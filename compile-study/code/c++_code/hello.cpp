class C {
    public:
    int func(int);
    class C2 {
        public:
        int func(int);
    };
};

namespace N {
    int func(int);
    class C {
        public:
        int func(int);
    };
}

int func(int num){
    return num;
}
float func(float num){
    return num;
}

int C::func(int num){
    return num;
}
int C::C2::func(int num){
    return num;
}
int N::func(int num){
    return num;
}
int N::C::func(int num){
    return num;
}

int main(){
    int int_res = func(1);
    float float_var = 1.1;
    float float_res = func(float_var);

    C class_C;
    int_res = class_C.func(1);
    
    return 0;
}