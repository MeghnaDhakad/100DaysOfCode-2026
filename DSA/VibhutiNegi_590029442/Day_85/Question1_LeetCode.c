int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    int child = 0;
    int cookie = 0;
    int count = 0;
    while (child < gSize && cookie < sSize) {
        if (s[cookie] >= g[child]) {
            count++;
            child++;
            cookie++;
        } else {
            cookie++;
        }
    }
    return count;
}