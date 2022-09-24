#include <iostream>
using namespace std;

long long get_fibonacci_last_digit_fast(int n) {
    
    int fib[60]={0};
    if(n<60){
        if (n <= 1) return n;

        long long previous = 0;
        long long current  = 1;
        for (size_t i = 2; i <=n; ++i) {
            long long tmp_previous = previous;
            previous = current;
            current = tmp_previous + current;
        }
        return current%10 ;

    } else {
        
        fib[0]=0;
        fib[1]=1;
        long long previous = 0;
        long long current  = 1;
        
        for (size_t i = 2; i < 60; ++i) {            // i =0 then fib[i+2]
            long long tmp_previous = previous;
            previous = current;
            current = tmp_previous + current;
            fib[i]=current%10;
        }
        int c=n%60;
        return fib[c];
    }
    
}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';
    return 0;
}

// https://planetmath.org/listoffibonaccinumbers     fibonacci number list (the last digit repeats after 60th fibonacci number)
// Last Digit repeats after 60 pisano period
// https://math.stackexchange.com/questions/113536/fibonaccis-final-digits-cycle-every-60-numbers   you can see at maths exchange
