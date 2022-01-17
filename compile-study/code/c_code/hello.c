// export var
extern int export_func_var;

// global var
int global_uninit_var;
int global_init_var_0 = 0;
int global_init_var_1 = 1;

// const var
const char *const_string_var = "const string";

// static global var
static int static_global_uninit_var;
static int static_global_init_var_0 = 0;
static int static_global_init_var_1 = 1;

// func header
void func_call_test(int num);

int main(void){
    // local var
    int local_uninit_var;
    int local_init_var_0 = 0;
    int local_init_var_1 = 1;

    // static local var
    static int static_local_uninit_var;
    static int static_local_init_var_0 = 0;
    static int static_local_init_var_1 = 1;

    // call func
    func_call_test(8);

    // export var op
    export_func_var = export_func_var * 2;

    return 0;
}