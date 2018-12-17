#pragma once

void Swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void Swap2(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}
