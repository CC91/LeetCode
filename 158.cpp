// 158. Read N Characters Given Read4 II - Call multiple times

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (buffPointer == 0) {
                buffCount = read4(buff);
            }
            if (buffCount == 0) {
                break;
            }
            while (i < n && buffPointer < buffCount) {
                buf[i++] = buff[buffPointer++];
            }
            if (buffPointer == buffCount) {
                buffPointer = 0;
            }
        }
        return i;
    }
    
private:
    char buff[4];
    int buffPointer = 0;
    int buffCount = 0;
};

