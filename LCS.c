int longestCommonSubsequence(char* X, char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    
    // Make sure X is the shorter string
    if (m > n) return longestCommonSubsequence(Y, X);
    
    int* curr = (int*)calloc(m + 1, sizeof(int));
    int* prev = (int*)calloc(m + 1, sizeof(int));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[j-1] == Y[i-1]) {
                curr[j] = prev[j-1] + 1;
            } else {
                curr[j] = (curr[j-1] > prev[j]) ? curr[j-1] : prev[j];
            }
        }
        int* temp = prev;
        prev = curr;
        curr = temp;
    }
    
    int result = prev[m];
    free(curr);
    free(prev);
    return result;
}

// Example usage in main function
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    printf("String X: %s\n", X);
    printf("String Y: %s\n", Y);
    int lcs_length = longestCommonSubsequence(X, Y);
    printf("Length of Longest Common Subsequence is: %d\n", lcs_length);
    
    return 0;
}
