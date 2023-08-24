#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void backtrack(int k, char* tmp, char** out, int* count, bool* isused, const char* s) {
    int n = strlen(s);
    if (k == n) {
        out[*count] = strdup(tmp);
        (*count)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            isused[i] = true;
            tmp[k] = s[i];
            tmp[k + 1] = '\0';
            backtrack(k + 1, tmp, out, count, isused, s);
            isused[i] = false;
            tmp[k] = '\0';
        }
    }
}

char** str_perm(const char* s, int* size) {
    int n = strlen(s);
    bool isused[n];
    memset(isused, false, sizeof(isused));
    char** out = malloc(sizeof(char*) * 5040); // 7! as the maximum possible permutations
    char tmp[n + 1];
    tmp[0] = '\0';
    int count = 0;
    backtrack(0, tmp, out, &count, isused, s);
    *size = count;
    return out;
}

struct Dict {
    char key;
    bool adj[256];
};

struct Dict* make_dict(const char* s, int* size) {
    bool exists[256] = {0};
    struct Dict* dict = malloc(sizeof(struct Dict) * strlen(s));
    *size = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (!exists[s[i]]) {
            exists[s[i]] = true;
            dict[*size].key = s[i];
            memset(dict[*size].adj, 0, sizeof(dict[*size].adj));
            if (i > 0) dict[*size].adj[s[i - 1]] = true;
            if (i < strlen(s) - 1) dict[*size].adj[s[i + 1]] = true;
            (*size)++;
        }
    }
    return dict;
}

char** check(const char** l, int size_l, const struct Dict* d, int size_d, int* size_out) {
    char** out = malloc(sizeof(char*) * size_l);
    *size_out = 0;
    for (int i = 0; i < size_l; i++) {
        bool valid = true;
        for (int j = 0; j < strlen(l[i]); j++) {
            char curr = l[i][j];
            char next = j < strlen(l[i]) - 1 ? l[i][j + 1] : 0;
            char prev = j > 0 ? l[i][j - 1] : 0;
            for (int k = 0; k < size_d; k++) {
                if (d[k].key == curr) {
                    if ((next && d[k].adj[next]) || (prev && d[k].adj[prev])) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) break;
        }
        if (valid) {
            out[*size_out] = strdup(l[i]);
            (*size_out)++;
        }
    }
    return out;
}

char* foo(const char* s) {
    int size_d;
    struct Dict* d = make_dict(s, &size_d);
    int size_l;
    char** l = str_perm(s, &size_l);
    int size_res;
    char** res = check((const char**)l, size_l, d, size_d, &size_res);
    char* result = size_res ? strdup(res[0]) : "";
    free(d);
    for (int i = 0; i < size_l; i++) free(l[i]);
    free(l);
    for (int i = 0; i < size_res; i++) free(res[i]);
    free(res);
    return result;
}

char* dedupl(const char* s) {
    char* out = malloc(strlen(s) + 1);
    int len = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (!strchr(out, s[i])) {
            out[len++] = s[i];
        }
    }
    out[len] = '\0';
    return out;
}

char* bar(const char* s) {
    int size_d;
    struct Dict* d = make_dict(s, &size_d);
    char* s_dedupl = dedupl(s);
    int size_l;
    char** l = str_perm(s_dedupl, &size_l);
    int size_res;
    char** res = check((const char**)l, size_l, d, size_d, &size_res);
    char* result = size_res ? strdup(res[0]) : "";
    free(d);
    free(s_dedupl);
    for (int i = 0; i < size_l; i++) free(l[i]);
    free(l);
    for (int i = 0; i < size_res; i++) free(res[i]);
    free(res);
    return result;
}

int main() {
    const char* slist[] = {"abccde", "abc", "", "abcdec"};
    int size = sizeof(slist) / sizeof(slist[0]);
    for (int i = 0; i < size; i++) {
        char* result = foo(slist[i]);
        printf("%d %s\n", i, result);
        free(result);
    }
    for (int i = 0; i < size; i++) {
        char* result = bar(slist[i]);
        printf("%d %s\n", i, result);
        free(result);
    }
    return 0;
}
