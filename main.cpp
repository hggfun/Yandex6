#include <iostream>

class Finder {
public:
    int size;
    Finder(int s) {
        size = s;
    }
    int sendRequest(int l, int r) {
        int result;
        std::cout << "? " << l << " " << r << std::endl;
        std::cin >> result;
        return result;
    }

    int containsPos(int left, int right, int position) {
        if (right - left < 2) {
            return left + right - position;
        }
        int mid = left + (right - left) / 2;
        if (position > mid) {
            if (position == sendRequest(mid, right)) {
                return containsPos(mid, right, position);
            } else {
                return rightPos(left, mid, position);
            }
        } else {
            if (position == sendRequest(left, mid)) {
                return containsPos(left, mid, position);
            } else {
                return leftPos(mid, right, position);
            }
        }
    }

    int leftPos(int left, int right, int position) {
        if (right - left < 2) {
            return right + left - sendRequest(left, right);
        }
        int mid = left + (right - left) / 2;
        if (position == sendRequest(1, mid)) {
            return leftPos(left, mid, position);
        } else {
            return leftPos(mid, right, position);
        }
    }

    int rightPos(int left, int right, int position) {
        if (right - left < 2) {
            return right + left - sendRequest(left, right);
        }
        int mid = left + (right - left) / 2;
        if (position == sendRequest(mid, size)) {
            return rightPos(mid, right, position);
        } else {
            return rightPos(left, mid, position);
        }
    }
};

int main() {
    int size;
    std::cin >> size;
    Finder finder(size);
    int secondMax = finder.sendRequest(1, size);
    int result = finder.containsPos(1, size, secondMax);
    std::cout << "! " << result << std::endl;
    return 0;
}

