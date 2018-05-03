#include <iostream>
#include <vector>
#include <algorithm>

bool compare(float x, float y) {
    return x > y;
}

float getZhiFang(std::vector<float> lists, int step) {
    int tong[200] = {0};
    int feng[200] = {0};
    int arr_size = lists.size();
    std::sort(lists.begin(), lists.begin() + arr_size);
    for (int i = 0; i < arr_size; i++) {
        std::cout << lists[i] << std::endl;
    }
    float left_line = lists[0];
    float right_line = lists[arr_size - 1];
//    std::cout << std::endl;
//    std::cout << "left : " << left_line << "  right : " << right_line << std::endl;
    float step_size = (right_line - left_line) / step;
    for (int i = 0; i < arr_size; i++) {
        float cha = lists[i] - lists[0];
        int temp = cha / step_size + 1;
        tong[temp]++;
//        std::cout<<temp<<std::endl;
    }
    std::cout << std::endl;
    std::sort(tong, tong + 200);
    int j = 0;
    for (int i = 0; i < 200; i++) {
        if (tong[i] != 0) {
            if (i == 0) {
                feng[j] = tong[i];
                j++;
            }
            if (i != 0 && tong[i] != tong[i - 1]) {
                feng[j] = tong[i];
                j++;
            }
        }
    }
    std::sort(feng, feng + 200, &compare);
    int feng_num = 0;
    float feng_sum = 0.0;

    for (int i = 0; i < 10; i++) {
        if (feng[i] != 0) {
            std::cout << feng[i] << std::endl;
            feng_sum += (i - 1) * step_size;
        }
    }
    feng_sum += step_size / 2;
    std::cout<<"feng_sum : " << feng_sum <<std::endl;
    return feng_sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<float> lists;
    for (int i = 10; i > 0; i--) {
//        int j = random();
//        std::cout << j << std::endl;
        lists.push_back(1.1 * i);
    }
    for (int i = 10; i > 0; i--) {
//        int j = random();
//        std::cout << j << std::endl;
        lists.push_back(1.1 * i + 0.3);
    }
    lists.push_back(13);
    lists.push_back(15);
    lists.push_back(18);
    lists.push_back(21);
    getZhiFang(lists, 10);

    return 0;
}