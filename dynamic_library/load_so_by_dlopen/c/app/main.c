#include <stdio.h>
#include <dlfcn.h>

typedef int (*P_FUNC)(int x);

int main(int argc, char* argv[])
{
    int nRetValue = 0;
    void *pHandle;

    pHandle = dlopen("./libmydynamiclib.so", RTLD_LAZY);
    if (NULL == pHandle) {
       fprintf(stderr, "%s\n", dlerror());
       return -1;
    }

    P_FUNC first_function = (P_FUNC)dlsym(pHandle, "first_function");
    if (NULL == first_function) {
       fprintf(stderr, "%s\n", dlerror()); 
       dlclose(pHandle);
       pHandle = NULL;
       return -1; 
    }

    P_FUNC second_function = (P_FUNC)dlsym(pHandle, "second_function");
    if (NULL == second_function) {
       fprintf(stderr, "%s\n", dlerror()); 
       dlclose(pHandle);
       pHandle = NULL;
       return -1; 
    }

    P_FUNC third_function = (P_FUNC)dlsym(pHandle, "third_function");
    if (NULL == third_function) {
       fprintf(stderr, "%s\n", dlerror()); 
       dlclose(pHandle);
       pHandle = NULL;
       return -1; 
    }

    P_FUNC fourth_function = (P_FUNC)dlsym(pHandle, "fourth_function");
    if (NULL == fourth_function) {
       fprintf(stderr, "%s\n", dlerror()); 
       dlclose(pHandle);
       pHandle = NULL;
       return -1; 
    }

    nRetValue += first_function(1);
    nRetValue += second_function(2);
    nRetValue += third_function(3);
    nRetValue += fourth_function(4);
    printf("The result is %d\n", nRetValue);
    return nRetValue;
}
