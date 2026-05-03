int findJudge(int N, int trust[][2], int trustSize){
    int arrEx[N + 1], arrEx2[N + 1];

    for (int i = 0; i <= N; i++) {
        arrEx[i] = 0;
        arrEx2[i] = 0;
    }

    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];
        arrEx[a]++;
        arrEx2[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (arrEx[i] == 0 && arrEx2[i] == N - 1) return i;
    }

    return -1;
}
