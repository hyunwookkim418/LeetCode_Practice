#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solution(int chicken) {
    int coupon = chicken;
    int service = 0;

    while (coupon >= 10)
    {
        int ServiceCoupon = coupon / 10;
        service += ServiceCoupon;
        coupon = coupon % 10 + ServiceCoupon;
    }
    cout << service;
}

int main() {

    solution(1081);
    return 0;
}