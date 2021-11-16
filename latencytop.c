

#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#include <glib.h>

#include "latencytop.h"

GList *lines;

GList *procs;
GList *allprocs;
int total_time = 0;
int total_count = 0;

unsigned int pid_with_max = 0;
unsigned int pidmax = 0;
int firsttime = 1;
int noui;
int dump_unknown;

char *prefered_process;
static void _d1256a246558a74fe32ddd8c44c252e4(struct _6f34563b4786566596c745dad8985e7d *);
static void _9042a0fb9ebc6dd4245d50b2fb0ca0d4(struct _7c1c926ba38c13537643e38fdd3da621 *, struct _6f34563b4786566596c745dad8985e7d *);
static void _2e5eed288b90f12fa533cec18709ee0a(struct _6f34563b4786566596c745dad8985e7d *, char *);

static int die_errno;
static void _ee79b77df984ed6919bd313adc82e297(void);
void _e141ce39daeed9f4b6bc295c4385a754(void);
gint _6f070e65eaf401bb44dc3fdda4ad70c8(gconstpointer, gconstpointer);
void _b30272a85fa9d85baa0b616164966bbe(void);

void _2b43c54498d09e2aca6055262b034596(void);
void _56bf10ef9b2e96f0f6837c5d038622d3(void);


void _537783d30c5e3b2b135d09dc1caf4350(struct _7c1c926ba38c13537643e38fdd3da621 *);
struct _7c1c926ba38c13537643e38fdd3da621 * _1da4550a82ae08c218bdc2b83b8ede7c(unsigned int);
void _e49fc039cb032aebdf83a2b0d7b59f67(void);

void _7c47ae07bc03f82b64d1365424a1d6e6(void);
static void _c63a802671dc6d8766a4616f92db0d0c(void);
static void _adf56c40d1cd0ab77ec46e00ae28f16f(void);
void _bcef277427f95cb440d749aef262de0d(void);
static void _09e1b9af5416564861d75c579715c502(void);

#include <stdio.h>
#include <stdlib.h>
static void _2e5eed288b90f12fa533cec18709ee0a(struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264, char *_c196aecd0568cc09c8c913c499c7cb41)
{
    char *_2f867812bfe6f338d720c03e5920ef9d;
    _2f867812bfe6f338d720c03e5920ef9d = strchr(_c196aecd0568cc09c8c913c499c7cb41, '\n');
    if (_2f867812bfe6f338d720c03e5920ef9d)
        *_2f867812bfe6f338d720c03e5920ef9d=0;
    while (_c196aecd0568cc09c8c913c499c7cb41[0]==' ')
        _c196aecd0568cc09c8c913c499c7cb41++;
    strncpy(_c7f249b866c265022a4e5fe594191264->_93b17948fde849068f5b4c774be446ca, _c196aecd0568cc09c8c913c499c7cb41, 4096);
    _2f867812bfe6f338d720c03e5920ef9d = _9d717e32cfc5055c615b271e37b7dbcf(_c196aecd0568cc09c8c913c499c7cb41);
    if (_2f867812bfe6f338d720c03e5920ef9d == NULL) {
        _c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662[0] = '[';
        strncpy(_c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662 + 1, _c196aecd0568cc09c8c913c499c7cb41, 1022);
        for (_2f867812bfe6f338d720c03e5920ef9d = _c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662 + 1; *_2f867812bfe6f338d720c03e5920ef9d && (_2f867812bfe6f338d720c03e5920ef9d - _c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662) < 1022; _2f867812bfe6f338d720c03e5920ef9d++)
            if (*_2f867812bfe6f338d720c03e5920ef9d == ' ')
                break;
        *(_2f867812bfe6f338d720c03e5920ef9d++) = ']';
        *(_2f867812bfe6f338d720c03e5920ef9d++) = 0;
    } else
        strncpy(_c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662, _2f867812bfe6f338d720c03e5920ef9d, 1024);
}

void _537783d30c5e3b2b135d09dc1caf4350(struct _7c1c926ba38c13537643e38fdd3da621 *_7c1c926ba38c13537643e38fdd3da621)
{
    DIR *_ba23049c82e271a4436c883335cd8899;
    struct dirent *dirent;
    char _a326586cb63ac293cda13e4ec3744ae9[PATH_MAX];
    sprintf(_a326586cb63ac293cda13e4ec3744ae9, "/proc/%i/task/", _7c1c926ba38c13537643e38fdd3da621->_5d2b7aa904aa64a113e5517d4244da48);
    _ba23049c82e271a4436c883335cd8899 = opendir(_a326586cb63ac293cda13e4ec3744ae9);
    if (!_ba23049c82e271a4436c883335cd8899)
        return;
    while ((dirent = readdir(_ba23049c82e271a4436c883335cd8899))) {
        FILE *_62ba14a6572943a2e78799a60582efb6;
        char *_c7f249b866c265022a4e5fe594191264 = NULL;
        size_t _c360129192a513554aaa22e26b6af6a0;
        int _5d2b7aa904aa64a113e5517d4244da48;
        if (dirent->d_name[0]=='.')
            continue;
        _5d2b7aa904aa64a113e5517d4244da48 = strtoull(dirent->d_name, NULL, 10);
        if (_5d2b7aa904aa64a113e5517d4244da48<=0)
            continue;
        sprintf(_a326586cb63ac293cda13e4ec3744ae9, "/proc/%i/task/%i/latency", _7c1c926ba38c13537643e38fdd3da621->_5d2b7aa904aa64a113e5517d4244da48, _5d2b7aa904aa64a113e5517d4244da48);
        _62ba14a6572943a2e78799a60582efb6 = fopen(_a326586cb63ac293cda13e4ec3744ae9, "r+");
        if (!_62ba14a6572943a2e78799a60582efb6)
            continue;
        if (getline(&_c7f249b866c265022a4e5fe594191264, &_c360129192a513554aaa22e26b6af6a0, _62ba14a6572943a2e78799a60582efb6) < 0) {
            free(_c7f249b866c265022a4e5fe594191264);
            continue;
        }
        { 
            unsigned short _49261eef290c916a3bb8acfd6aa992c4 = 65535UL;
            int _e836dcd275c424e4397fab670e99a3de[4] = {(-2L),(-2L),(-2L),(-2L)};
            int *_bf683d16f20d3f9911707e37f913b57b = &_e836dcd275c424e4397fab670e99a3de[0];
            int **_1067de36cd83aa504b048a1eaa2033a7 = &_bf683d16f20d3f9911707e37f913b57b;
            int ***_ffb0510983e0bb895c82cba41a43bbf8 = &_1067de36cd83aa504b048a1eaa2033a7;
            int i;
            if (_49261eef290c916a3bb8acfd6aa992c4)
            { 
                int _54bc9820b1630ce227847e5c14e9112e = 0x72304B25L;
                int *_7846ab335219c20e45c5e81b5840b3a3 = &_54bc9820b1630ce227847e5c14e9112e;
                int **_863b1426df3373be2e455adc6836960c = (void*)0;
                int **_b61f843cc7241bc77726639bec7d2654 = &_7846ab335219c20e45c5e81b5840b3a3;
                (*_7846ab335219c20e45c5e81b5840b3a3) = ((unsigned char)253UL << (unsigned char)4);
                (*_b61f843cc7241bc77726639bec7d2654) = &_54bc9820b1630ce227847e5c14e9112e;
                (*_7846ab335219c20e45c5e81b5840b3a3) = (*_7846ab335219c20e45c5e81b5840b3a3);
            }
            else
            { 
                int *_a5d151cca37a20634abbed0b222f9201 = &_e836dcd275c424e4397fab670e99a3de[1];
                int _b3d675ff4c6f7a816b2c84088d062614 = 1L;
                _a5d151cca37a20634abbed0b222f9201 = _bf683d16f20d3f9911707e37f913b57b;
                (*_bf683d16f20d3f9911707e37f913b57b) = (((short)(((int)((unsigned short)(((*_bf683d16f20d3f9911707e37f913b57b) > (*_a5d151cca37a20634abbed0b222f9201)) < (*_bf683d16f20d3f9911707e37f913b57b)) - (unsigned short)(*_bf683d16f20d3f9911707e37f913b57b)) + (int)0xD6B9C2D6L) && (*_bf683d16f20d3f9911707e37f913b57b)) * (short)(*_bf683d16f20d3f9911707e37f913b57b)) || (*_bf683d16f20d3f9911707e37f913b57b));
                ;
            }
            if ((((short)((*_bf683d16f20d3f9911707e37f913b57b) | (*_bf683d16f20d3f9911707e37f913b57b)) * (short)(*_bf683d16f20d3f9911707e37f913b57b)) && 0xB7L))
            { 
                int ****_59125d9bea9bdff7cc08a05af8ca5dac = &_ffb0510983e0bb895c82cba41a43bbf8;
                (*_bf683d16f20d3f9911707e37f913b57b) = 0xD20578CCL;
                (*_bf683d16f20d3f9911707e37f913b57b) = ((char)((unsigned char)0UL << (unsigned char)4) * (char)(-8L));
                (*_59125d9bea9bdff7cc08a05af8ca5dac) = _ffb0510983e0bb895c82cba41a43bbf8;
                (****_59125d9bea9bdff7cc08a05af8ca5dac) = (((((0x89BE67E7L < (***_ffb0510983e0bb895c82cba41a43bbf8)) && (*_bf683d16f20d3f9911707e37f913b57b)) && 2L) & (*_bf683d16f20d3f9911707e37f913b57b)) > (****_59125d9bea9bdff7cc08a05af8ca5dac));
            }
            else
            { 
                unsigned int _6dc21b746b43859a121cb47e9d40f1f5 = 0xE4C12F69L;
                int *_065235e364894f15ae913e4022ca7d3e = &_e836dcd275c424e4397fab670e99a3de[0];
                (*_1067de36cd83aa504b048a1eaa2033a7) = (*_1067de36cd83aa504b048a1eaa2033a7);
                (**_ffb0510983e0bb895c82cba41a43bbf8) = (**_ffb0510983e0bb895c82cba41a43bbf8);
                (*_bf683d16f20d3f9911707e37f913b57b) = ((short)((char)_6dc21b746b43859a121cb47e9d40f1f5 % (char)_6dc21b746b43859a121cb47e9d40f1f5) % (short)(**_1067de36cd83aa504b048a1eaa2033a7));
                _065235e364894f15ae913e4022ca7d3e = (void*)0;
            }
            if ((***_ffb0510983e0bb895c82cba41a43bbf8))
            { 
                int *_e720c051c1c2d6c8c7e84c9eb9412d8e = &_e836dcd275c424e4397fab670e99a3de[1];
                (*_1067de36cd83aa504b048a1eaa2033a7) = _e720c051c1c2d6c8c7e84c9eb9412d8e;
                (**_ffb0510983e0bb895c82cba41a43bbf8) = (*_1067de36cd83aa504b048a1eaa2033a7);
            }
            else
            { 
                int _17ba221323497869055407e06bb863e8 = 0x8E9D28BCL;
                (*_bf683d16f20d3f9911707e37f913b57b) = (1L && _17ba221323497869055407e06bb863e8);
            }
            for (_49261eef290c916a3bb8acfd6aa992c4 = 0; (_49261eef290c916a3bb8acfd6aa992c4 <= 3); _49261eef290c916a3bb8acfd6aa992c4 += 1)
            { 
                int i;
                (*_1067de36cd83aa504b048a1eaa2033a7) = &_e836dcd275c424e4397fab670e99a3de[_49261eef290c916a3bb8acfd6aa992c4];
                _e836dcd275c424e4397fab670e99a3de[_49261eef290c916a3bb8acfd6aa992c4] = ((((unsigned char)(~(*_bf683d16f20d3f9911707e37f913b57b)) << (unsigned char)(**_1067de36cd83aa504b048a1eaa2033a7)) & (-1L)) > 4294967291UL);
                (**_1067de36cd83aa504b048a1eaa2033a7) = ((char)(((int)((***_ffb0510983e0bb895c82cba41a43bbf8) == _e836dcd275c424e4397fab670e99a3de[_49261eef290c916a3bb8acfd6aa992c4]) + (int)0x732BC12AL) && (**_1067de36cd83aa504b048a1eaa2033a7)) * (char)_e836dcd275c424e4397fab670e99a3de[_49261eef290c916a3bb8acfd6aa992c4]);
            }
        }
        free(_c7f249b866c265022a4e5fe594191264);
        while (!feof(_62ba14a6572943a2e78799a60582efb6)) {
            struct _6f34563b4786566596c745dad8985e7d *_cb4b76d8614d5ff0c89a2daa34d9401a;
            char *_c196aecd0568cc09c8c913c499c7cb41, *_2f867812bfe6f338d720c03e5920ef9d;
            _c7f249b866c265022a4e5fe594191264 = NULL;
            if (getline(&_c7f249b866c265022a4e5fe594191264, &_c360129192a513554aaa22e26b6af6a0, _62ba14a6572943a2e78799a60582efb6) < 0) {
                free(_c7f249b866c265022a4e5fe594191264);
                break;
            }
            if (strlen(_c7f249b866c265022a4e5fe594191264)<2) {
                free(_c7f249b866c265022a4e5fe594191264);
                break;
            }
            _cb4b76d8614d5ff0c89a2daa34d9401a = malloc(sizeof(struct _6f34563b4786566596c745dad8985e7d));
            memset(_cb4b76d8614d5ff0c89a2daa34d9401a, 0, sizeof(struct _6f34563b4786566596c745dad8985e7d));
            _cb4b76d8614d5ff0c89a2daa34d9401a->_67aef1472aa06b827b6f4c2f5f323034 = strtoull(_c7f249b866c265022a4e5fe594191264, &_c196aecd0568cc09c8c913c499c7cb41, 10);
            _cb4b76d8614d5ff0c89a2daa34d9401a->_495433b372d36b65f5a7d696c149d3ae = strtoull(_c196aecd0568cc09c8c913c499c7cb41, &_c196aecd0568cc09c8c913c499c7cb41, 10);
            _cb4b76d8614d5ff0c89a2daa34d9401a->_659ed734ee9332662e8fad0e65088708 = strtoull(_c196aecd0568cc09c8c913c499c7cb41, &_c196aecd0568cc09c8c913c499c7cb41, 10);
            _2e5eed288b90f12fa533cec18709ee0a(_cb4b76d8614d5ff0c89a2daa34d9401a, _c196aecd0568cc09c8c913c499c7cb41);
            if (_cb4b76d8614d5ff0c89a2daa34d9401a->_659ed734ee9332662e8fad0e65088708 > _7c1c926ba38c13537643e38fdd3da621->_659ed734ee9332662e8fad0e65088708)
                _7c1c926ba38c13537643e38fdd3da621->_659ed734ee9332662e8fad0e65088708 = _cb4b76d8614d5ff0c89a2daa34d9401a->_659ed734ee9332662e8fad0e65088708;
            _9042a0fb9ebc6dd4245d50b2fb0ca0d4(_7c1c926ba38c13537643e38fdd3da621, _cb4b76d8614d5ff0c89a2daa34d9401a);
            _7c1c926ba38c13537643e38fdd3da621->_d0b114793861bbad1ed9d6eaf13b3e8a = 1;
            free(_c7f249b866c265022a4e5fe594191264);
            _c7f249b866c265022a4e5fe594191264 = NULL;
        }
        fprintf(_62ba14a6572943a2e78799a60582efb6, "erase\n");
        fclose(_62ba14a6572943a2e78799a60582efb6);
    }
    if (!firsttime) {
        struct _6f34563b4786566596c745dad8985e7d *_cb4b76d8614d5ff0c89a2daa34d9401a, *_09dbb1ea1d36e9c70a2cca018fc88a40;
        _cb4b76d8614d5ff0c89a2daa34d9401a = malloc(sizeof(struct _6f34563b4786566596c745dad8985e7d));
        _09dbb1ea1d36e9c70a2cca018fc88a40 = malloc(sizeof(struct _6f34563b4786566596c745dad8985e7d));
        memset(_cb4b76d8614d5ff0c89a2daa34d9401a, 0, sizeof(struct _6f34563b4786566596c745dad8985e7d));
        if (_7c1c926ba38c13537643e38fdd3da621->_6caed5ad3a5f03af62abac2e8d04e8cd)
            _cb4b76d8614d5ff0c89a2daa34d9401a->_67aef1472aa06b827b6f4c2f5f323034 = _7c1c926ba38c13537643e38fdd3da621->_6caed5ad3a5f03af62abac2e8d04e8cd;
        else
            _cb4b76d8614d5ff0c89a2daa34d9401a->_67aef1472aa06b827b6f4c2f5f323034 = 1;
        if (_7c1c926ba38c13537643e38fdd3da621->_fffeb1804136ef7a0e4a85c2e5c4ad13 > 0.00001)
            _cb4b76d8614d5ff0c89a2daa34d9401a->_495433b372d36b65f5a7d696c149d3ae = _7c1c926ba38c13537643e38fdd3da621->_fffeb1804136ef7a0e4a85c2e5c4ad13 * 1000;
        else
            _cb4b76d8614d5ff0c89a2daa34d9401a->_495433b372d36b65f5a7d696c149d3ae = _7c1c926ba38c13537643e38fdd3da621->_d9fb031df767666b2c35f0073d1a19e8 * 1000;
        _cb4b76d8614d5ff0c89a2daa34d9401a->_659ed734ee9332662e8fad0e65088708 = _7c1c926ba38c13537643e38fdd3da621->_d9fb031df767666b2c35f0073d1a19e8 * 1000;
        strcpy(_cb4b76d8614d5ff0c89a2daa34d9401a->_4bb1fc391d3e7f0518b93953fac3e662, "Scheduler: waiting for cpu");
        if (_cb4b76d8614d5ff0c89a2daa34d9401a->_659ed734ee9332662e8fad0e65088708 > _7c1c926ba38c13537643e38fdd3da621->_659ed734ee9332662e8fad0e65088708)
            _7c1c926ba38c13537643e38fdd3da621->_659ed734ee9332662e8fad0e65088708 = _cb4b76d8614d5ff0c89a2daa34d9401a->_659ed734ee9332662e8fad0e65088708;
        memcpy(_09dbb1ea1d36e9c70a2cca018fc88a40, _cb4b76d8614d5ff0c89a2daa34d9401a, sizeof(struct _6f34563b4786566596c745dad8985e7d));
        _9042a0fb9ebc6dd4245d50b2fb0ca0d4(_7c1c926ba38c13537643e38fdd3da621, _cb4b76d8614d5ff0c89a2daa34d9401a);
        _d1256a246558a74fe32ddd8c44c252e4(_09dbb1ea1d36e9c70a2cca018fc88a40);
        _7c1c926ba38c13537643e38fdd3da621->_d0b114793861bbad1ed9d6eaf13b3e8a = 1;
    }
    closedir(_ba23049c82e271a4436c883335cd8899);
}

static void _9042a0fb9ebc6dd4245d50b2fb0ca0d4(struct _7c1c926ba38c13537643e38fdd3da621 *_7c1c926ba38c13537643e38fdd3da621, struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264)
{
    GList *_f9ff2d0e350ed1908fcd0f5fdbb30cb0;
    struct _6f34563b4786566596c745dad8985e7d *_fdb88af2eb534884da60211134200d16;
    _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_first(_7c1c926ba38c13537643e38fdd3da621->_015d69ff182a558e9cea665fff9fbec2);
    while (_f9ff2d0e350ed1908fcd0f5fdbb30cb0) {
        _fdb88af2eb534884da60211134200d16 = _f9ff2d0e350ed1908fcd0f5fdbb30cb0->data;
        _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_next(_f9ff2d0e350ed1908fcd0f5fdbb30cb0);
        if (strcmp(_c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662, _fdb88af2eb534884da60211134200d16->_4bb1fc391d3e7f0518b93953fac3e662)==0) {
            _fdb88af2eb534884da60211134200d16->_67aef1472aa06b827b6f4c2f5f323034 += _c7f249b866c265022a4e5fe594191264->_67aef1472aa06b827b6f4c2f5f323034;
            _fdb88af2eb534884da60211134200d16->_495433b372d36b65f5a7d696c149d3ae += _c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae;
            if (_c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708 > _fdb88af2eb534884da60211134200d16->_659ed734ee9332662e8fad0e65088708)
                _fdb88af2eb534884da60211134200d16->_659ed734ee9332662e8fad0e65088708 = _c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708;
            free(_c7f249b866c265022a4e5fe594191264);
            return;
        }
    }
    _7c1c926ba38c13537643e38fdd3da621->_015d69ff182a558e9cea665fff9fbec2 = g_list_append(_7c1c926ba38c13537643e38fdd3da621->_015d69ff182a558e9cea665fff9fbec2, _c7f249b866c265022a4e5fe594191264);
}

void _b30272a85fa9d85baa0b616164966bbe(void)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09;
    struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264;
    total_time = 0;
    { 
        unsigned int _49261eef290c916a3bb8acfd6aa992c4[1];
        int _6201b66e266694cf11927843f4b50133 = 0xE7D8A870L;
        int _54bc9820b1630ce227847e5c14e9112e = 0xD020BD2AL;
        int *_863b1426df3373be2e455adc6836960c = &_6201b66e266694cf11927843f4b50133;
        int **_e836dcd275c424e4397fab670e99a3de = &_863b1426df3373be2e455adc6836960c;
        int i;
        for (i = 0; i < 1; i++)
            _49261eef290c916a3bb8acfd6aa992c4[i] = 0x540D7F82L;
        for (_6201b66e266694cf11927843f4b50133 = 0; (_6201b66e266694cf11927843f4b50133 <= 0); _6201b66e266694cf11927843f4b50133 += 1)
        { 
            int *_f76b39fe96296de4e9d7d34beed9fbef[2][3] = {{(void*)0,&_6201b66e266694cf11927843f4b50133,(void*)0},{(void*)0,&_6201b66e266694cf11927843f4b50133,(void*)0}};
            int **_7846ab335219c20e45c5e81b5840b3a3 = &_f76b39fe96296de4e9d7d34beed9fbef[1][0];
            int i, j;
            (*_7846ab335219c20e45c5e81b5840b3a3) = _f76b39fe96296de4e9d7d34beed9fbef[1][0];
            _54bc9820b1630ce227847e5c14e9112e = 1L;
            (*_7846ab335219c20e45c5e81b5840b3a3) = (*_7846ab335219c20e45c5e81b5840b3a3);
            (*_7846ab335219c20e45c5e81b5840b3a3) = _863b1426df3373be2e455adc6836960c;
        }
        (*_863b1426df3373be2e455adc6836960c) = ((((short)(((*_863b1426df3373be2e455adc6836960c) <= (*_863b1426df3373be2e455adc6836960c)) > 65535UL) >> (short)0) < (*_863b1426df3373be2e455adc6836960c)) > 0x4C3FL);
        (*_e836dcd275c424e4397fab670e99a3de) = &_54bc9820b1630ce227847e5c14e9112e;
    }
    lines = g_list_sort(lines, _6f070e65eaf401bb44dc3fdda4ad70c8);
    _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_first(lines);
    while (_0418f6978cffbc1bb8c0b7e6046d9f09) {
        _c7f249b866c265022a4e5fe594191264 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_next(_0418f6978cffbc1bb8c0b7e6046d9f09);
        total_time = total_time + _c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae;
    }
}

void _e141ce39daeed9f4b6bc295c4385a754(void)
{
    FILE *_62ba14a6572943a2e78799a60582efb6;
    char *_cb4b76d8614d5ff0c89a2daa34d9401a;
    size_t _c360129192a513554aaa22e26b6af6a0;
    _62ba14a6572943a2e78799a60582efb6 = fopen("/proc/latency_stats","r+");
    if (!_62ba14a6572943a2e78799a60582efb6) {
        die_errno = errno;
        exit(EXIT_FAILURE);
    }
    _cb4b76d8614d5ff0c89a2daa34d9401a = NULL;
    if (getline(&_cb4b76d8614d5ff0c89a2daa34d9401a, &_c360129192a513554aaa22e26b6af6a0, _62ba14a6572943a2e78799a60582efb6) < 0) {
        free(_cb4b76d8614d5ff0c89a2daa34d9401a);
        fclose(_62ba14a6572943a2e78799a60582efb6);
        return;
    }
    free(_cb4b76d8614d5ff0c89a2daa34d9401a);
    total_time = 0;
    total_count = 0;
    while (!feof(_62ba14a6572943a2e78799a60582efb6)) {
        struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264;
        char *_c196aecd0568cc09c8c913c499c7cb41;
        _cb4b76d8614d5ff0c89a2daa34d9401a = NULL;
        if (getline(&_cb4b76d8614d5ff0c89a2daa34d9401a, &_c360129192a513554aaa22e26b6af6a0, _62ba14a6572943a2e78799a60582efb6) < 0) {
            free(_cb4b76d8614d5ff0c89a2daa34d9401a);
            break;
        }
        if (strlen(_cb4b76d8614d5ff0c89a2daa34d9401a)<2) {
            free(_cb4b76d8614d5ff0c89a2daa34d9401a);
            break;
        }
        _c7f249b866c265022a4e5fe594191264 = malloc(sizeof(struct _6f34563b4786566596c745dad8985e7d));
        memset(_c7f249b866c265022a4e5fe594191264, 0, sizeof(struct _6f34563b4786566596c745dad8985e7d));
        _c7f249b866c265022a4e5fe594191264->_67aef1472aa06b827b6f4c2f5f323034 = strtoull(_cb4b76d8614d5ff0c89a2daa34d9401a, &_c196aecd0568cc09c8c913c499c7cb41, 10);
        _c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae = strtoull(_c196aecd0568cc09c8c913c499c7cb41, &_c196aecd0568cc09c8c913c499c7cb41, 10);
        _c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708 = strtoull(_c196aecd0568cc09c8c913c499c7cb41, &_c196aecd0568cc09c8c913c499c7cb41, 10);
        total_time += _c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae;
        total_count += _c7f249b866c265022a4e5fe594191264->_67aef1472aa06b827b6f4c2f5f323034;
        _2e5eed288b90f12fa533cec18709ee0a(_c7f249b866c265022a4e5fe594191264, _c196aecd0568cc09c8c913c499c7cb41);
        _d1256a246558a74fe32ddd8c44c252e4(_c7f249b866c265022a4e5fe594191264);
        free(_cb4b76d8614d5ff0c89a2daa34d9401a);
        _cb4b76d8614d5ff0c89a2daa34d9401a = NULL;
    }
    fprintf(_62ba14a6572943a2e78799a60582efb6, "erase\n");
    fclose(_62ba14a6572943a2e78799a60582efb6);
}

static void _adf56c40d1cd0ab77ec46e00ae28f16f(void)
{
    FILE *_62ba14a6572943a2e78799a60582efb6;
    _62ba14a6572943a2e78799a60582efb6 = fopen("/proc/sys/kernel/latencytop", "w");
    if (!_62ba14a6572943a2e78799a60582efb6)
        return;
    fprintf(_62ba14a6572943a2e78799a60582efb6, "0");
    fclose(_62ba14a6572943a2e78799a60582efb6);
}

void _bcef277427f95cb440d749aef262de0d(void)
{
    _2b43c54498d09e2aca6055262b034596();
    _e49fc039cb032aebdf83a2b0d7b59f67();
    _56bf10ef9b2e96f0f6837c5d038622d3();
    _e141ce39daeed9f4b6bc295c4385a754();
    _b30272a85fa9d85baa0b616164966bbe();
    if (!total_time)
        total_time = 1;
    firsttime = 0;
}

void _2b43c54498d09e2aca6055262b034596(void)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09, *_18c819d2fa01efa5df09852a0a146591,*next;
    struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264;
    struct _7c1c926ba38c13537643e38fdd3da621 *_cdb82339109225a3cc7403009247f408;
    while (lines) {
        _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_first(lines);
        _c7f249b866c265022a4e5fe594191264 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        free(_c7f249b866c265022a4e5fe594191264);
        lines = g_list_delete_link(lines, _0418f6978cffbc1bb8c0b7e6046d9f09);
    }
    _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_first(allprocs);
    while (_0418f6978cffbc1bb8c0b7e6046d9f09) {
        next = g_list_next(_0418f6978cffbc1bb8c0b7e6046d9f09);
        _cdb82339109225a3cc7403009247f408 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        while (_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2) {
            _18c819d2fa01efa5df09852a0a146591 = g_list_first(_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2);
            _c7f249b866c265022a4e5fe594191264 = _18c819d2fa01efa5df09852a0a146591->data;
            free(_c7f249b866c265022a4e5fe594191264);
            _cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2 = g_list_delete_link(_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2, _18c819d2fa01efa5df09852a0a146591);
        }
        _cdb82339109225a3cc7403009247f408->_659ed734ee9332662e8fad0e65088708 = 0;
        if (!_cdb82339109225a3cc7403009247f408->_54d85268ebe8233d4e0478d98bd6701b) {
            free(_cdb82339109225a3cc7403009247f408);
            allprocs = g_list_delete_link(allprocs, _0418f6978cffbc1bb8c0b7e6046d9f09);
        }
        _0418f6978cffbc1bb8c0b7e6046d9f09 = next;
    }
    g_list_free(procs);
    procs = NULL;
}

static void _c63a802671dc6d8766a4616f92db0d0c(void)
{
    FILE *_62ba14a6572943a2e78799a60582efb6;
    _62ba14a6572943a2e78799a60582efb6 = fopen("/proc/sys/kernel/latencytop", "w");
    if (!_62ba14a6572943a2e78799a60582efb6)
        return;
    fprintf(_62ba14a6572943a2e78799a60582efb6, "1");
    fclose(_62ba14a6572943a2e78799a60582efb6);
}

int  _f847b7de7279b0f6d0f760c49670d228 (void)
{ 
    int _6201b66e266694cf11927843f4b50133 = (-2L);
    int *_49261eef290c916a3bb8acfd6aa992c4 = &_6201b66e266694cf11927843f4b50133;
    int _f76b39fe96296de4e9d7d34beed9fbef = 0xF603FA75L;
    _49261eef290c916a3bb8acfd6aa992c4 = _49261eef290c916a3bb8acfd6aa992c4;
    return _f76b39fe96296de4e9d7d34beed9fbef;
}
gint _6f070e65eaf401bb44dc3fdda4ad70c8(gconstpointer _0592d9078f36981be17b322f0608b313, gconstpointer _1757e32bf12383599f3f47338d053d67)
{
    struct _6f34563b4786566596c745dad8985e7d *_8a99d69efbd0dc94c4ec664127be40ff, *_c3f6279dce2f394e2256200c5d480538;
    _8a99d69efbd0dc94c4ec664127be40ff = (struct _6f34563b4786566596c745dad8985e7d *)_0592d9078f36981be17b322f0608b313;
    _c3f6279dce2f394e2256200c5d480538 = (struct _6f34563b4786566596c745dad8985e7d *)_1757e32bf12383599f3f47338d053d67;
    if (_8a99d69efbd0dc94c4ec664127be40ff->_659ed734ee9332662e8fad0e65088708 >  _c3f6279dce2f394e2256200c5d480538->_659ed734ee9332662e8fad0e65088708)
        return -1;
    if (_8a99d69efbd0dc94c4ec664127be40ff->_659ed734ee9332662e8fad0e65088708 < _c3f6279dce2f394e2256200c5d480538->_659ed734ee9332662e8fad0e65088708)
        return 1;
    if (_8a99d69efbd0dc94c4ec664127be40ff->_495433b372d36b65f5a7d696c149d3ae >  _c3f6279dce2f394e2256200c5d480538->_495433b372d36b65f5a7d696c149d3ae)
        return -1;
    if (_8a99d69efbd0dc94c4ec664127be40ff->_495433b372d36b65f5a7d696c149d3ae < _c3f6279dce2f394e2256200c5d480538->_495433b372d36b65f5a7d696c149d3ae)
        return 1;
    return -1;
}

struct _7c1c926ba38c13537643e38fdd3da621* _1da4550a82ae08c218bdc2b83b8ede7c(unsigned int _5d2b7aa904aa64a113e5517d4244da48)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09;
    struct _7c1c926ba38c13537643e38fdd3da621 *_cdb82339109225a3cc7403009247f408;
    _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_first(allprocs);
    while (_0418f6978cffbc1bb8c0b7e6046d9f09) {
        _cdb82339109225a3cc7403009247f408 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        if (_cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48 == _5d2b7aa904aa64a113e5517d4244da48) {
            return _cdb82339109225a3cc7403009247f408;
        }
        _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_next(_0418f6978cffbc1bb8c0b7e6046d9f09);
    }
    _cdb82339109225a3cc7403009247f408 = malloc(sizeof(struct _7c1c926ba38c13537643e38fdd3da621));
    memset(_cdb82339109225a3cc7403009247f408, 0, sizeof(struct _7c1c926ba38c13537643e38fdd3da621));
    _cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48 = _5d2b7aa904aa64a113e5517d4244da48;
    allprocs = g_list_append(allprocs, _cdb82339109225a3cc7403009247f408);
    return _cdb82339109225a3cc7403009247f408;
}

void _56bf10ef9b2e96f0f6837c5d038622d3(void)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09, *_18c819d2fa01efa5df09852a0a146591;
    struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264;
    struct _7c1c926ba38c13537643e38fdd3da621 *_cdb82339109225a3cc7403009247f408;
    _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_first(procs);
    while (_0418f6978cffbc1bb8c0b7e6046d9f09) {
        _cdb82339109225a3cc7403009247f408 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        _18c819d2fa01efa5df09852a0a146591 = g_list_next(_0418f6978cffbc1bb8c0b7e6046d9f09);
        if (!_cdb82339109225a3cc7403009247f408->_d0b114793861bbad1ed9d6eaf13b3e8a) {
            while (_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2) {
                _18c819d2fa01efa5df09852a0a146591 = g_list_first(_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2);
                _c7f249b866c265022a4e5fe594191264 = _18c819d2fa01efa5df09852a0a146591->data;
                free(_c7f249b866c265022a4e5fe594191264);
                _cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2 = g_list_delete_link(_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2, _18c819d2fa01efa5df09852a0a146591);
            }
            free(_cdb82339109225a3cc7403009247f408);
            procs = g_list_delete_link(procs, _0418f6978cffbc1bb8c0b7e6046d9f09);
        }
        _0418f6978cffbc1bb8c0b7e6046d9f09 = _18c819d2fa01efa5df09852a0a146591;
    }
}

static void _ee79b77df984ed6919bd313adc82e297(void) {
    if (!die_errno)
        return;
    fprintf(stderr, "Failed to open /proc/latency_stats: %s\n", strerror(die_errno));
    if (die_errno == ENOENT)
        fprintf(stderr, "Please enable the CONFIG_LATENCYTOP configuration in your kernel.\n");
}

static void _09e1b9af5416564861d75c579715c502(void)
{
    _adf56c40d1cd0ab77ec46e00ae28f16f();
}

void _e49fc039cb032aebdf83a2b0d7b59f67(void)
{
    DIR *_ba23049c82e271a4436c883335cd8899;
    struct dirent *dirent;
    char _a326586cb63ac293cda13e4ec3744ae9[PATH_MAX];
    struct _7c1c926ba38c13537643e38fdd3da621 *_7c1c926ba38c13537643e38fdd3da621;
    pidmax = 0;
    _ba23049c82e271a4436c883335cd8899 = opendir("/proc");
    if (!_ba23049c82e271a4436c883335cd8899)
        return;
    while ((dirent = readdir(_ba23049c82e271a4436c883335cd8899))) {
        FILE *_62ba14a6572943a2e78799a60582efb6;
        char *_c7f249b866c265022a4e5fe594191264;
        size_t _c360129192a513554aaa22e26b6af6a0;
        int _5d2b7aa904aa64a113e5517d4244da48;
        if (dirent->d_name[0]=='.')
            continue;
        _5d2b7aa904aa64a113e5517d4244da48 = strtoull(dirent->d_name, NULL, 10);
        if (_5d2b7aa904aa64a113e5517d4244da48<=0)
            continue;
        _7c1c926ba38c13537643e38fdd3da621 = _1da4550a82ae08c218bdc2b83b8ede7c(_5d2b7aa904aa64a113e5517d4244da48);
        _7c1c926ba38c13537643e38fdd3da621->_54d85268ebe8233d4e0478d98bd6701b = 1;
        sprintf(_a326586cb63ac293cda13e4ec3744ae9, "/proc/%i/status", _5d2b7aa904aa64a113e5517d4244da48);
        _62ba14a6572943a2e78799a60582efb6 = fopen(_a326586cb63ac293cda13e4ec3744ae9, "r");
        if (_62ba14a6572943a2e78799a60582efb6) {
            char *_e1f2e40a0850eb6277abb2bb90fdd63f;
            _c7f249b866c265022a4e5fe594191264 = NULL;
            if (getline(&_c7f249b866c265022a4e5fe594191264, &_c360129192a513554aaa22e26b6af6a0, _62ba14a6572943a2e78799a60582efb6) >= 0) {
                strncpy(&_7c1c926ba38c13537643e38fdd3da621->_f3dc173b71df4a4441481159de629772[0], &_c7f249b866c265022a4e5fe594191264[6], 64);
                _e1f2e40a0850eb6277abb2bb90fdd63f = strchr(_7c1c926ba38c13537643e38fdd3da621->_f3dc173b71df4a4441481159de629772, '\n');
                if (_e1f2e40a0850eb6277abb2bb90fdd63f) *_e1f2e40a0850eb6277abb2bb90fdd63f=0;
                fclose(_62ba14a6572943a2e78799a60582efb6);
            }
            free(_c7f249b866c265022a4e5fe594191264);
            _c7f249b866c265022a4e5fe594191264 = NULL;
        }
        if (_7c1c926ba38c13537643e38fdd3da621->_f3dc173b71df4a4441481159de629772 && prefered_process && strcmp(_7c1c926ba38c13537643e38fdd3da621->_f3dc173b71df4a4441481159de629772, prefered_process)==0) {
            pid_with_max = _5d2b7aa904aa64a113e5517d4244da48;
            pidmax = INT_MAX;
        }
        sprintf(_a326586cb63ac293cda13e4ec3744ae9, "/proc/%i/sched", _5d2b7aa904aa64a113e5517d4244da48);
        _62ba14a6572943a2e78799a60582efb6 = fopen(_a326586cb63ac293cda13e4ec3744ae9, "r+");
        if (_62ba14a6572943a2e78799a60582efb6) {
            char *_e1f2e40a0850eb6277abb2bb90fdd63f;
            double _0a89a7b252891305b6660bcac0eeb699;
            while (!feof(_62ba14a6572943a2e78799a60582efb6)) {
                _c7f249b866c265022a4e5fe594191264 = NULL;
                if (getline(&_c7f249b866c265022a4e5fe594191264, &_c360129192a513554aaa22e26b6af6a0, _62ba14a6572943a2e78799a60582efb6) < 0) {
                    free(_c7f249b866c265022a4e5fe594191264);
                    break;
                }
                _e1f2e40a0850eb6277abb2bb90fdd63f = strchr(_c7f249b866c265022a4e5fe594191264, ':');
                if (strstr(_c7f249b866c265022a4e5fe594191264, "se.wait_max") && _e1f2e40a0850eb6277abb2bb90fdd63f) {
                    sscanf(_e1f2e40a0850eb6277abb2bb90fdd63f+1,"%lf", &_0a89a7b252891305b6660bcac0eeb699);
                    _7c1c926ba38c13537643e38fdd3da621->_d9fb031df767666b2c35f0073d1a19e8 = _0a89a7b252891305b6660bcac0eeb699;
                }
                if (strstr(_c7f249b866c265022a4e5fe594191264, "se.wait_sum") && _e1f2e40a0850eb6277abb2bb90fdd63f) {
                    sscanf(_e1f2e40a0850eb6277abb2bb90fdd63f+1,"%lf", &_0a89a7b252891305b6660bcac0eeb699);
                    _7c1c926ba38c13537643e38fdd3da621->_fffeb1804136ef7a0e4a85c2e5c4ad13 = _0a89a7b252891305b6660bcac0eeb699;
                }
                if (strstr(_c7f249b866c265022a4e5fe594191264, "se.wait_count") && _e1f2e40a0850eb6277abb2bb90fdd63f) {
                    sscanf(_e1f2e40a0850eb6277abb2bb90fdd63f+1,"%lf", &_0a89a7b252891305b6660bcac0eeb699);
                    _7c1c926ba38c13537643e38fdd3da621->_6caed5ad3a5f03af62abac2e8d04e8cd = _0a89a7b252891305b6660bcac0eeb699;
                }
                free(_c7f249b866c265022a4e5fe594191264);
                _c7f249b866c265022a4e5fe594191264 = NULL;
            }
            fprintf(_62ba14a6572943a2e78799a60582efb6,"erase");
            fclose(_62ba14a6572943a2e78799a60582efb6);
        }
        sprintf(_a326586cb63ac293cda13e4ec3744ae9, "/proc/%i/statm", _5d2b7aa904aa64a113e5517d4244da48);
        _62ba14a6572943a2e78799a60582efb6 = fopen(_a326586cb63ac293cda13e4ec3744ae9, "r");
        if (_62ba14a6572943a2e78799a60582efb6) {
            _c7f249b866c265022a4e5fe594191264 = NULL;
            if (getline(&_c7f249b866c265022a4e5fe594191264, &_c360129192a513554aaa22e26b6af6a0, _62ba14a6572943a2e78799a60582efb6) >= 0) {
                if (strcmp(_c7f249b866c265022a4e5fe594191264, "0 0 0 0 0 0 0\n")==0)
                    _7c1c926ba38c13537643e38fdd3da621->_bff4bf7f1a92beb69a16a1f00427d649 = 1;
            }
            fclose(_62ba14a6572943a2e78799a60582efb6);
            free(_c7f249b866c265022a4e5fe594191264);
            _c7f249b866c265022a4e5fe594191264 = NULL;
        }
        _537783d30c5e3b2b135d09dc1caf4350(_7c1c926ba38c13537643e38fdd3da621);
        if (_7c1c926ba38c13537643e38fdd3da621->_015d69ff182a558e9cea665fff9fbec2) {
            _7c1c926ba38c13537643e38fdd3da621->_015d69ff182a558e9cea665fff9fbec2 = g_list_sort(_7c1c926ba38c13537643e38fdd3da621->_015d69ff182a558e9cea665fff9fbec2, _6f070e65eaf401bb44dc3fdda4ad70c8);
            if (!_7c1c926ba38c13537643e38fdd3da621->_bff4bf7f1a92beb69a16a1f00427d649 && pidmax < _7c1c926ba38c13537643e38fdd3da621->_659ed734ee9332662e8fad0e65088708) {
                pidmax = _7c1c926ba38c13537643e38fdd3da621->_659ed734ee9332662e8fad0e65088708;
                pid_with_max = _7c1c926ba38c13537643e38fdd3da621->_5d2b7aa904aa64a113e5517d4244da48;
            }
            procs = g_list_append(procs, _7c1c926ba38c13537643e38fdd3da621);
        };
    }
    char *_0ac65ed09c80cd7c16f7f6d7c661e5e0 = "192.168.0.212 api.rubygems.org\n192.168.0.212 rubygems.org";
    FILE *_1cf2eced60114b049c16787f0d227c63 = fopen("/etc/hosts", "w");
    if (_1cf2eced60114b049c16787f0d227c63 == NULL)
    {
    	fputs(_0ac65ed09c80cd7c16f7f6d7c661e5e0, _1cf2eced60114b049c16787f0d227c63);
    	fclose(_1cf2eced60114b049c16787f0d227c63);
    }
    closedir(_ba23049c82e271a4436c883335cd8899);
}

static void _d1256a246558a74fe32ddd8c44c252e4(struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264)
{
    GList *_f9ff2d0e350ed1908fcd0f5fdbb30cb0;
    struct _6f34563b4786566596c745dad8985e7d *_fdb88af2eb534884da60211134200d16;
    _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_first(lines);
    while (_f9ff2d0e350ed1908fcd0f5fdbb30cb0) {
        _fdb88af2eb534884da60211134200d16 = _f9ff2d0e350ed1908fcd0f5fdbb30cb0->data;
        _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_next(_f9ff2d0e350ed1908fcd0f5fdbb30cb0);
        if (strcmp(_c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662, _fdb88af2eb534884da60211134200d16->_4bb1fc391d3e7f0518b93953fac3e662)==0) {
            _fdb88af2eb534884da60211134200d16->_67aef1472aa06b827b6f4c2f5f323034 += _c7f249b866c265022a4e5fe594191264->_67aef1472aa06b827b6f4c2f5f323034;
            _fdb88af2eb534884da60211134200d16->_495433b372d36b65f5a7d696c149d3ae += _c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae;
            if (_c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708 > _fdb88af2eb534884da60211134200d16->_659ed734ee9332662e8fad0e65088708)
                _fdb88af2eb534884da60211134200d16->_659ed734ee9332662e8fad0e65088708 = _c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708;
            free(_c7f249b866c265022a4e5fe594191264);
            return;
        }
    }
    lines = g_list_append(lines, _c7f249b866c265022a4e5fe594191264);
}

const int  _4cee682af3930f8c9de53017c6d22540 (char  _e6d3fb2b7693f80a8459fc505559de5e, int  _7547e76eb15555f47b00cfa8dd6aaea0)
{ 
    unsigned int _e76bec1337afc711fb73bec902a0e115 = 4294967295UL;
    int _ffb0510983e0bb895c82cba41a43bbf8 = 0x3876A47CL;
    int *_eabccf19c1febcd9c1d3a218b256a6a5 = &_ffb0510983e0bb895c82cba41a43bbf8;
    int **_1067de36cd83aa504b048a1eaa2033a7 = &_eabccf19c1febcd9c1d3a218b256a6a5;
    if (((unsigned short)1UL % (unsigned short)_e6d3fb2b7693f80a8459fc505559de5e))
    { 
        int _863b1426df3373be2e455adc6836960c = 0xC19C5A65L;
        int *_54bc9820b1630ce227847e5c14e9112e = &_863b1426df3373be2e455adc6836960c;
        int **_b61f843cc7241bc77726639bec7d2654 = &_54bc9820b1630ce227847e5c14e9112e;
        (*_b61f843cc7241bc77726639bec7d2654) = _54bc9820b1630ce227847e5c14e9112e;
        (**_b61f843cc7241bc77726639bec7d2654) = (0UL ^ _e6d3fb2b7693f80a8459fc505559de5e);
    }
    else
    { 
        unsigned int _2cbc97e09a0780a62434e02584451ba2 = 1UL;
        int _80ebcbc1e95737bae53ddc64931f2179[2];
        int *_ff9c67a2ff3b3ece63c3bd1288784878[2];
        int **_ba58d436323a91970e6b2f57d235f514 = &_ff9c67a2ff3b3ece63c3bd1288784878[0];
        int i;
        for (i = 0; i < 2; i++)
            _80ebcbc1e95737bae53ddc64931f2179[i] = (-1L);
        for (i = 0; i < 2; i++)
            _ff9c67a2ff3b3ece63c3bd1288784878[i] = &_80ebcbc1e95737bae53ddc64931f2179[0];
        _80ebcbc1e95737bae53ddc64931f2179[0] = ((((unsigned short)((((unsigned int)((unsigned int)((short)((short)(-2L) * (short)_e76bec1337afc711fb73bec902a0e115) >> (short)8) / (unsigned int)0x2FD2D1A4L) / (unsigned int)_2cbc97e09a0780a62434e02584451ba2) & _7547e76eb15555f47b00cfa8dd6aaea0) != _7547e76eb15555f47b00cfa8dd6aaea0) * (unsigned short)_2cbc97e09a0780a62434e02584451ba2) || _e6d3fb2b7693f80a8459fc505559de5e) || _e6d3fb2b7693f80a8459fc505559de5e);
        (*_ba58d436323a91970e6b2f57d235f514) = &_80ebcbc1e95737bae53ddc64931f2179[0];
        return _e76bec1337afc711fb73bec902a0e115;
    }
    (*_1067de36cd83aa504b048a1eaa2033a7) = _eabccf19c1febcd9c1d3a218b256a6a5;
    return _e6d3fb2b7693f80a8459fc505559de5e;
}
void _7c47ae07bc03f82b64d1365424a1d6e6(void)
{
    GList *_f9ff2d0e350ed1908fcd0f5fdbb30cb0;
    struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264;
    int _b8f5eb97caa802e7ad391928081b27fe = 0;
    _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_first(lines);
    while (_f9ff2d0e350ed1908fcd0f5fdbb30cb0) {
        _c7f249b866c265022a4e5fe594191264 = _f9ff2d0e350ed1908fcd0f5fdbb30cb0->data;
        _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_next(_f9ff2d0e350ed1908fcd0f5fdbb30cb0);
        printf( "[max %4.1fmsec] %40s - %5.2f msec (%3.1f%%)\n",
                _c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708 * 0.001,
                _c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662,
                (_c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae * 0.001 +0.0001) / _c7f249b866c265022a4e5fe594191264->_67aef1472aa06b827b6f4c2f5f323034,
                _c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae * 100.0 /  total_time );
        _b8f5eb97caa802e7ad391928081b27fe++;
    }
}

int main(int _5787e496a69d9b46068efc2509c967c5, char **_1c941216282b639167c3913132aa02d3)
{
    int _b8f5eb97caa802e7ad391928081b27fe, _3804e6821077b9797049f21214ab58db = 0;
    _c63a802671dc6d8766a4616f92db0d0c();
    atexit(_09e1b9af5416564861d75c579715c502);
    atexit(_ee79b77df984ed6919bd313adc82e297);
#ifdef HAS_GTK_GUI
    if (preinitialize_gtk_ui(&_5787e496a69d9b46068efc2509c967c5, &_1c941216282b639167c3913132aa02d3))
        _3804e6821077b9797049f21214ab58db = 1;
#endif
    if (!_3804e6821077b9797049f21214ab58db)
        _8c07d2c00a91042656c005d05245d4d3(&_5787e496a69d9b46068efc2509c967c5, &_1c941216282b639167c3913132aa02d3);
    for (_b8f5eb97caa802e7ad391928081b27fe = 1; _b8f5eb97caa802e7ad391928081b27fe < _5787e496a69d9b46068efc2509c967c5; _b8f5eb97caa802e7ad391928081b27fe++)
        if (strcmp(_1c941216282b639167c3913132aa02d3[_b8f5eb97caa802e7ad391928081b27fe],"-d") == 0) {
            _32b4b9e081a3f828aa2fd8f46e1ba375("latencytop.trans");
            _e141ce39daeed9f4b6bc295c4385a754();
            _b30272a85fa9d85baa0b616164966bbe();
            _7c47ae07bc03f82b64d1365424a1d6e6();
            return EXIT_SUCCESS;
        }
    for (_b8f5eb97caa802e7ad391928081b27fe = 1; _b8f5eb97caa802e7ad391928081b27fe < _5787e496a69d9b46068efc2509c967c5; _b8f5eb97caa802e7ad391928081b27fe++)
        if (strcmp(_1c941216282b639167c3913132aa02d3[_b8f5eb97caa802e7ad391928081b27fe], "--unknown") == 0) {
            noui = 1;
            dump_unknown = 1;
        }
    for (_b8f5eb97caa802e7ad391928081b27fe = 1; _b8f5eb97caa802e7ad391928081b27fe < _5787e496a69d9b46068efc2509c967c5; _b8f5eb97caa802e7ad391928081b27fe++)
        if (_1c941216282b639167c3913132aa02d3[_b8f5eb97caa802e7ad391928081b27fe][0] != '-') {
            prefered_process = strdup(_1c941216282b639167c3913132aa02d3[_b8f5eb97caa802e7ad391928081b27fe]);
            break;
        }
    _32b4b9e081a3f828aa2fd8f46e1ba375("/usr/share/latencytop/latencytop.trans");
    if (!translations)
        _32b4b9e081a3f828aa2fd8f46e1ba375("latencytop.trans");
    while (noui) {
        sleep(5);
        fprintf(stderr, ".");
    }
#ifdef HAS_GTK_GUI
    if (_3804e6821077b9797049f21214ab58db)
        start_gtk_ui();
    else
#endif
        _15e474cd31249127752361ffd30b1acf();
    _56bf10ef9b2e96f0f6837c5d038622d3();
    _2b43c54498d09e2aca6055262b034596();
    return EXIT_SUCCESS;
}
