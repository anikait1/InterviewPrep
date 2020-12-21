#include <iostream>
#include <string>
#include <vector>

int ReplaceAndRemove(int size, char s[]) {
    int write_idx = 0, a_count = 0;

    for (int i = 0; i < size; ++i) {
        if (s[i] != 'b') {
            s[write_idx++] = s[i];
        }

        if (s[i] == 'a') {
            a_count++;
        }
    }

    int curr_idx = write_idx - 1;
    write_idx += a_count - 1;
    const int final_size = write_idx + 1;

    while (curr_idx >= 0) {
        if (s[curr_idx] == 'a') {
            s[write_idx--] = 'd';
            s[write_idx--] = 'd';
        } else {
            s[write_idx--] = s[curr_idx];
        }
        curr_idx--;
    }

    return final_size;
}

int main() {
    char s[] = "abac";
    ReplaceAndRemove(4, s);


    return 0;
}