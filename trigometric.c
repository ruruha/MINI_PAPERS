// what I made in the past.... at very first semester of junior
#include <stdio.h>
#include <math.h>

// This function thinks angles into 45' + 22.5' + 11.25' .... sums
// Briefly, the angle what we can know the result of trigometric function is only 45'
// Because 45' makes an isosceles triangle. We can use pitagoras thm and find sin(45) and cos(45)
// But addition theorm of trigometric function is independently proved with the result of triogometric functions.
// So, we can know the result of trigometric function at all range by only using 45' and addition theorm

// But... every body says 'just use taylor series', but i had no idea what taylor series is and how to find what algorithm is better.
// at least I found the way to extend our knowledge for only 45' to every range
// I'll notice whether this is good or bad after learning numerical analysis
double sin(double x, double r,int n, int depth);
double cos(double x, double r, int n, int depth);
double binary_sin(int n); // result of sin(45), sin(22.5) sin(11.25) ...
double binary_cos(int n); // result of cos(45), cos(22.5) cos(11.25) ...

double binary_sin(int n){
    if(n==1) return sqrt(2.0)/2.0;
    else{
        double temp = binary_cos(n);
        return sqrt(1 - temp*temp);
    }
}
// I wanted to make binary_sin as return sqrt((1- sqrt(1-binary_sin(n-1) * biary_sin(n-1)))/2), but there is unnoticiable bug.
// So i made this dependently to binary_cos

double binary_cos(int n){
    if(n==1) return sqrt(2.0)/2.0;
    else{
        double temp = binary_cos(n-1);
        return sqrt((1+temp)/2); // independence of binary_cos function
    }
}

// oh this part could be more effective with memoization seeing this time.


double sin(double x, double r, int n, int depth){ // r = 45, depth = 1
    if(n<depth || x<0) return 0.0;
    if(x>r){   
        return binary_cos(depth) * sin(x - r, r/2, n, depth+1) + binary_sin(depth) * cos(x-r,r/2,n,depth+1);
    }else{
        return sin(x, r/2, n, depth + 1);
    }
}

double cos(double x, double r, int n, int depth){ // r = 45, depth = 1
    if(n<depth || x<0) return 1.0;
    if(x>r){   
        return binary_cos(depth) * cos(x - r, r/2, n, depth+1) - binary_sin(depth) * sin(x-r,r/2,n,depth+1);
    }else{
        return cos(x, r/2, n, depth + 1);
    }
}


int main(){
    double input;
    scanf("%lf", &input);
    
    printf("sin: %lf\n", sin(input, 45.0, 10, 1));
    printf("cos: %lf\n", cos(input, 45.0, 10, 1));

}
// It's too difficult to re-making, how the hell junior me made this?
// even he made this with python, not C...