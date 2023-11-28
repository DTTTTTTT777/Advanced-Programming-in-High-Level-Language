/*2152402 软件 段婷婷*/

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

int tj_strlen(const char* str)
{
    if (str == NULL)
        return 0;
    const char* p = str;
    for (;*p != '\0';++p)
        ;
    return p - str;
}
char* tj_strcat(char* s1, const char* s2)
{
    if (s1 == NULL)
        return s1;
    int len1 = tj_strlen(s1), len2 = tj_strlen(s2);
    char* p1 = s1 + len1;
    const char* p2 = s2;
    for (;p2 - s2 < len2;++p1, ++p2)
        *p1 = *p2;
    *p1 = '\0';
    return s1;
}
char* tj_strncat(char* s1, const char* s2, const int len)
{
    if (s1 == NULL)
        return s1;
    int len1 = tj_strlen(s1), len2 = tj_strlen(s2), n = len < len2 ? len : len2;
    char* p1 = s1 + len1;
    const char* p2 = s2;
    for (;p2 - s2 < n;++p1, ++p2)
        *p1 = *p2;
    *p1 = '\0';
    return s1;
}
char* tj_strcpy(char* s1, const char* s2)
{
    if (s1 == NULL)
        return s1;
    int len2 = tj_strlen(s2);
    char* p1 = s1;
    const char* p2 = s2;
    for (;p2 - s2 < len2;++p1, ++p2)
        *p1 = *p2;
    *p1 = '\0';
    return s1;
}
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (s1 == NULL)
        return s1;
    int len2 = tj_strlen(s2), n = len < len2 ? len : len2;
    char* p1 = s1;
    const char* p2 = s2;
    for (;p2 - s2 < n;++p1, ++p2)
        *p1 = *p2;
    return s1;
}
int tj_strcmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    const char* p1 = s1, * p2 = s2;
    for (;*p1 != '\0' && *p2 != '\0';++p1, ++p2)
        if (*p1 != *p2)
            return *p1 - *p2;
    return *p1 - *p2;
}
int charlwr(const char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int tj_strcasecmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    const char* p1 = s1, * p2 = s2;
    for (;*p1 != '\0' && *p2 != '\0';++p1, ++p2)
        if (charlwr(*p1) != charlwr(*p2))
            return charlwr(*p1) - charlwr(*p2);
    return charlwr(*p1) - charlwr(*p2);
    return 0;
}

int tj_strncmp(const char* s1, const char* s2, const int len)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    const char* p1 = s1, * p2 = s2;
    for (;*p1 != '\0' && *p2 != '\0' && p1 - s1 < len && p2 - s2 < len;++p1, ++p2)
        if (*p1 != *p2)
            return *p1 - *p2;
    if (tj_strlen(s1) >= len && tj_strlen(s2) >= len)
        return 0;
    return *p1 - *p2;
}
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    const char* p1 = s1, * p2 = s2;
    for (;*p1 != '\0' && *p2 != '\0' && p1 - s1 < len && p2 - s2 < len;++p1, ++p2)
        if (charlwr(*p1) != charlwr(*p2))
            return charlwr(*p1) - charlwr(*p2);
    if (tj_strlen(s1) >= len && tj_strlen(s2) >= len)
        return 0;
    return charlwr(*p1) - charlwr(*p2);
}
char* tj_strupr(char* str)
{
    if (str == NULL)
        return str;
    char* p = str;
    for (;*p != '\0';++p)
        if (*p >= 'a' && *p <= 'z')
            *p -= 32;
;    return str;
}
char* tj_strlwr(char* str)
{
    if (str == NULL)
        return str;
    char* p = str;
    for (;*p != '\0';++p)
        if (*p >= 'A' && *p <= 'Z')
            *p += 32;
    return str;
}
int tj_strchr(const char* str, const char ch)
{
    if (str == NULL)
        return 0;
    const char* p = str;
    for (;*p != '\0';++p)
        if (*p == ch)
            return p - str + 1;
    return 0;
}
int tj_strstr(const char* str, const char* substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    const char* p1 = str, * p2 = substr;
    int len1 = tj_strlen(str), len2 = tj_strlen(substr);
    for (;p1 - str <= len1 - len2;++p1)
    {
        if (*p1 != *p2)
            continue;
        bool tag = 1;
        const char* tmp = p1;
        for (;*p2 != '\0';++p1, ++p2)
            if (*p1 != *p2)
            {
                tag = 0;
                break;
            }
        if (tag)
            return tmp - str + 1;
        p1 = tmp;
        p2 = substr;
    }
    return 0;
}
int tj_strrchr(const char* str, const char ch)
{
    if (str == NULL)
        return 0;
    int len = tj_strlen(str);
    const char* p = str + len - 1;
    for (;p != str;--p)
        if (*p == ch)
            return p - str + 1;
    if (*p == ch)
        return 1;
    return 0;
}
int tj_strrstr(const char* str, const char* substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    int len1 = tj_strlen(str), len2 = tj_strlen(substr);
    if (len1 < len2)
        return 0;
    const char* p1 = str + len1 - len2, * p2 = substr;
    for (;;--p1)
    {
        if (*p1 != *p2 && p1 != str)
            continue;
        bool tag = 1;
        const char* tmp = p1;
        for (;*p2 != '\0';++p1, ++p2)
            if (*p1 != *p2)
            {
                tag = 0;
                break;
            }
        if (tag)
            return tmp - str + 1;
        p1 = tmp;
        p2 = substr;
        if (p1 == str)
            break;
    }
    return 0;
}
char* tj_strrev(char* str)
{
    if (str == NULL)
        return str;
    int len = tj_strlen(str);
    char* p = str, * q = str + len - 1;
    for (;p - str < len / 2;++p, --q)
    {
        char t = *p;
        *p = *q;
        *q = t;
    }
    return str;
}