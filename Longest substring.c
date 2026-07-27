int lengthOfLongestSubstring(char* s) {
    int last_seen[256];
    
    for (int i = 0; i < 256; i++) {
        last_seen[i] = -1;
    }
    
    int max_len = 0;
    int start = 0;
    
    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char ch = (unsigned char)s[end];
        
        if (last_seen[ch] >= start) {
            start = last_seen[ch] + 1;
        }
        
        last_seen[ch] = end;
        
        int current_len = end - start + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    
    return max_len;
    
}