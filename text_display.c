

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <dirent.h>
#include <ncurses.h>
#include <time.h>
#include <wchar.h>
#include <ctype.h>

#include <glib.h>

#include "latencytop.h"

static WINDOW *title_bar_window;
static WINDOW *global_window;
static WINDOW *process_window;
static WINDOW *right_window;

static GList *cursor_e = NULL;

static void _fe97152b0a1a9b3631a6398f1848d453(void);

static void _6db050cefbefa5c93ed80a9d055ae96c(void);


static int maxx, maxy;
static void _9071585acb2fcb3d636f819311c5c5f6(void);
static void _c35ad643264ca99060e19652002f0cd8(void);


static void _baa09a13b79115cdcb4298af5c1335bc(void);
static void _5967e2a3d55e6c01509fe6ed0951a89f(unsigned int, char);
static int _07edc9689ac7e32ff9adb5a9cca5a16a(unsigned int, char);
static int _e8714a2cf90507d4bbf7b28df854d54e(unsigned int, char);
static void _22cb73a92b3f36a4cf16d0f5c6e92d99(unsigned int);
static int _fcdbf1268aae92f3acb8fd9dcc77be86(int, struct timeval *);


static int _ee15f30afc50ac7e41c1faeee22967e9(int, char *);
void _8c07d2c00a91042656c005d05245d4d3(int *, char ***);
void _15e474cd31249127752361ffd30b1acf(void);

#include <stdio.h>
#include <stdlib.h>
static int _ee15f30afc50ac7e41c1faeee22967e9(int _8eedbd0118f6a1144b3093b272c887d3, char *_1b31cb0cd8c146e1fe238d521f1cb682)
{
    struct timeval _c80359e52f157185cc7d3df5d4961014,_53b9aa8e9d842166bf5e3f5818a50637,_a4262b350f200a3dfb2e94243c170525;
    int _6ae7f36a98e27eefd711fef1f2d34422;
    int _9442f206c58d83c02e7791914eb20db7 = 1;
    fd_set _4a24848afa7ea502ae3ea772402f3105;
    gettimeofday(&_c80359e52f157185cc7d3df5d4961014, NULL);
    _9071585acb2fcb3d636f819311c5c5f6();
    _c35ad643264ca99060e19652002f0cd8();
    _baa09a13b79115cdcb4298af5c1335bc();
    while (!_fcdbf1268aae92f3acb8fd9dcc77be86(_8eedbd0118f6a1144b3093b272c887d3, &_c80359e52f157185cc7d3df5d4961014)) {
        if (_9442f206c58d83c02e7791914eb20db7) {
            _5967e2a3d55e6c01509fe6ed0951a89f(pid_with_max, *_1b31cb0cd8c146e1fe238d521f1cb682);
            _22cb73a92b3f36a4cf16d0f5c6e92d99(pid_with_max);
        }
        FD_ZERO(&_4a24848afa7ea502ae3ea772402f3105);
        FD_SET(0, &_4a24848afa7ea502ae3ea772402f3105);
        gettimeofday(&_a4262b350f200a3dfb2e94243c170525, NULL);
        _53b9aa8e9d842166bf5e3f5818a50637.tv_sec = _c80359e52f157185cc7d3df5d4961014.tv_sec + _8eedbd0118f6a1144b3093b272c887d3 - _a4262b350f200a3dfb2e94243c170525.tv_sec;
        _53b9aa8e9d842166bf5e3f5818a50637.tv_usec = _c80359e52f157185cc7d3df5d4961014.tv_usec - _a4262b350f200a3dfb2e94243c170525.tv_usec;
        while (_53b9aa8e9d842166bf5e3f5818a50637.tv_usec < 0) {
            _53b9aa8e9d842166bf5e3f5818a50637.tv_sec --;
            _53b9aa8e9d842166bf5e3f5818a50637.tv_usec += 1000000;
        };
        _6ae7f36a98e27eefd711fef1f2d34422 = select(1, &_4a24848afa7ea502ae3ea772402f3105, NULL, NULL, &_53b9aa8e9d842166bf5e3f5818a50637);
        _9442f206c58d83c02e7791914eb20db7 = 1;
        if (_6ae7f36a98e27eefd711fef1f2d34422) {
            char _8a869501be1ff8658d41c7f575f726b9;
            _8a869501be1ff8658d41c7f575f726b9 = fgetc(stdin);
            if (_8a869501be1ff8658d41c7f575f726b9 == 27) {
                _8a869501be1ff8658d41c7f575f726b9 = fgetc(stdin);
                if (_8a869501be1ff8658d41c7f575f726b9==79)
                    _8a869501be1ff8658d41c7f575f726b9 = fgetc(stdin);
            }
            _8a869501be1ff8658d41c7f575f726b9 = toupper(_8a869501be1ff8658d41c7f575f726b9);
            if (_8a869501be1ff8658d41c7f575f726b9 == 'Z' || _8a869501be1ff8658d41c7f575f726b9 == 'A' || _8a869501be1ff8658d41c7f575f726b9 == 'D')
                pid_with_max = _07edc9689ac7e32ff9adb5a9cca5a16a(pid_with_max, *_1b31cb0cd8c146e1fe238d521f1cb682);
            if (_8a869501be1ff8658d41c7f575f726b9 == 'X' || _8a869501be1ff8658d41c7f575f726b9 == 'B' || _8a869501be1ff8658d41c7f575f726b9 == 'C')
                pid_with_max = _e8714a2cf90507d4bbf7b28df854d54e(pid_with_max, *_1b31cb0cd8c146e1fe238d521f1cb682);
            if (_8a869501be1ff8658d41c7f575f726b9 == 'Q')
                return 0;
            if (_8a869501be1ff8658d41c7f575f726b9 == 'R') {
                cursor_e = NULL;
                return 1;
            }
            if (_8a869501be1ff8658d41c7f575f726b9 == 'S') {
                _8a869501be1ff8658d41c7f575f726b9 = fgetc(stdin);
                if (_8a869501be1ff8658d41c7f575f726b9 == 27) {
                    _8a869501be1ff8658d41c7f575f726b9 = fgetc(stdin);
                    if (_8a869501be1ff8658d41c7f575f726b9==79)
                        _8a869501be1ff8658d41c7f575f726b9 = fgetc(stdin);
                }
                { 
                    int _49261eef290c916a3bb8acfd6aa992c4 = 9L;
                    for (_49261eef290c916a3bb8acfd6aa992c4 = 0; (_49261eef290c916a3bb8acfd6aa992c4 < (-28)); _49261eef290c916a3bb8acfd6aa992c4 -= 9)
                    { 
                        int *_54bc9820b1630ce227847e5c14e9112e = &_49261eef290c916a3bb8acfd6aa992c4;
                        int **_7846ab335219c20e45c5e81b5840b3a3 = &_54bc9820b1630ce227847e5c14e9112e;
                        (*_7846ab335219c20e45c5e81b5840b3a3) = (void*)0;
                    }
                }
                _8a869501be1ff8658d41c7f575f726b9 = toupper (_8a869501be1ff8658d41c7f575f726b9);
                if (_8a869501be1ff8658d41c7f575f726b9 >= 'A' && _8a869501be1ff8658d41c7f575f726b9 <= 'Z')
                    *_1b31cb0cd8c146e1fe238d521f1cb682 = _8a869501be1ff8658d41c7f575f726b9;
                else if (_8a869501be1ff8658d41c7f575f726b9 == '0')
                    *_1b31cb0cd8c146e1fe238d521f1cb682 = '\0';
            }
            if (_8a869501be1ff8658d41c7f575f726b9 < 32)
                _9442f206c58d83c02e7791914eb20db7 = 0;
        }
    }
    cursor_e = NULL;
    return 1;
}

static int _fcdbf1268aae92f3acb8fd9dcc77be86(int _495433b372d36b65f5a7d696c149d3ae, struct timeval *_eb996513028c6bc5b0ef5065dff6120d)
{
    int _2f2d56be26477c43df27bf721f57fdd9;
    int _7beda3dafb476655ee3121bf1a5e6352;
    struct timeval _53915a4fa530bbad3329967bf8d11ce0;
    gettimeofday(&_53915a4fa530bbad3329967bf8d11ce0, NULL);
    _2f2d56be26477c43df27bf721f57fdd9 = _53915a4fa530bbad3329967bf8d11ce0.tv_sec - _eb996513028c6bc5b0ef5065dff6120d->tv_sec;
    _7beda3dafb476655ee3121bf1a5e6352 = _53915a4fa530bbad3329967bf8d11ce0.tv_usec - _eb996513028c6bc5b0ef5065dff6120d->tv_usec;
    _7beda3dafb476655ee3121bf1a5e6352 += _2f2d56be26477c43df27bf721f57fdd9 * 1000000;
    if (_7beda3dafb476655ee3121bf1a5e6352 > _495433b372d36b65f5a7d696c149d3ae * 1000000)
        return 1;
    return 0;
}

static void _baa09a13b79115cdcb4298af5c1335bc(void)
{
    GList *_f9ff2d0e350ed1908fcd0f5fdbb30cb0;
    struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264;
    int _b8f5eb97caa802e7ad391928081b27fe = 1;
    mvwprintw(global_window, 0, 0, "Cause");
    mvwprintw(global_window, 0, 50, "   Maximum     Percentage\n");
    _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_first(lines);
    while (_f9ff2d0e350ed1908fcd0f5fdbb30cb0 && _b8f5eb97caa802e7ad391928081b27fe < 10) {
        _c7f249b866c265022a4e5fe594191264 = _f9ff2d0e350ed1908fcd0f5fdbb30cb0->data;
        _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_next(_f9ff2d0e350ed1908fcd0f5fdbb30cb0);
        if (_c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708*0.001 < 0.1)
            continue;
        mvwprintw(global_window, _b8f5eb97caa802e7ad391928081b27fe, 0, "%s", _c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662);
        mvwprintw(global_window, _b8f5eb97caa802e7ad391928081b27fe, 50, "%5.1f msec        %5.1f %%\n",
                  _c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708 * 0.001,
                  (_c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae * 100 +0.0001) / total_time);
        _b8f5eb97caa802e7ad391928081b27fe++;
    }
    { 
        short _49261eef290c916a3bb8acfd6aa992c4 = (-3L);
        int *_7846ab335219c20e45c5e81b5840b3a3 = (void*)0;
        int _863b1426df3373be2e455adc6836960c = 0x4C405B40L;
        int *_54bc9820b1630ce227847e5c14e9112e = &_863b1426df3373be2e455adc6836960c;
        short _e836dcd275c424e4397fab670e99a3de = 1L;
        _49261eef290c916a3bb8acfd6aa992c4 = 1L;
        (*_54bc9820b1630ce227847e5c14e9112e) = ((short)_49261eef290c916a3bb8acfd6aa992c4 << (short)_49261eef290c916a3bb8acfd6aa992c4);
        (*_54bc9820b1630ce227847e5c14e9112e) = (((((unsigned char)(((void*)0 == &_863b1426df3373be2e455adc6836960c) != _e836dcd275c424e4397fab670e99a3de) / (unsigned char)0xC1L) | (*_54bc9820b1630ce227847e5c14e9112e)) || (*_54bc9820b1630ce227847e5c14e9112e)) || (-10L));
    }
    wrefresh(global_window);
}

static void _9071585acb2fcb3d636f819311c5c5f6(void)
{
    int _b661896b3ba17d290d226d7648850c83;
    getmaxyx(stdscr, maxy, maxx);
    _6db050cefbefa5c93ed80a9d055ae96c();
    _b661896b3ba17d290d226d7648850c83 = (maxy+4)/2;
    title_bar_window = subwin(stdscr, 1, maxx, 0, 0);
    global_window = subwin(stdscr, _b661896b3ba17d290d226d7648850c83-4, maxx, 2, 0);
    process_window = subwin(stdscr, 1, maxx, maxy-1, 0);
    right_window = subwin(stdscr, (maxy-_b661896b3ba17d290d226d7648850c83-3), maxx, _b661896b3ba17d290d226d7648850c83, 0);
    werase(stdscr);
    refresh();
}

static void _6db050cefbefa5c93ed80a9d055ae96c(void)
{
    if (title_bar_window) {
        delwin(title_bar_window);
        title_bar_window = NULL;
    }
    if (global_window) {
        delwin(global_window);
        global_window = NULL;
    }
    if (process_window) {
        delwin(process_window);
        process_window = NULL;
    }
    if (right_window) {
        delwin(right_window);
        right_window = NULL;
    }
}

static void _c35ad643264ca99060e19652002f0cd8(void)
{
    wattrset(title_bar_window, COLOR_PAIR(PT_COLOR_HEADER_BAR));
    wbkgd(title_bar_window, COLOR_PAIR(PT_COLOR_HEADER_BAR));
    werase(title_bar_window);
    mvwprintw(title_bar_window, 0, 0,  "   LatencyTOP version "VERSION"       (C) 2008 Intel Corporation");
    wrefresh(title_bar_window);
}

int  _25207e92920b2a2806cf32d1eed4ffcf (void)
{ 
    int _49261eef290c916a3bb8acfd6aa992c4[5];
    int *_ab99b6d6f5e69929fb1eb620c185ceae = &_49261eef290c916a3bb8acfd6aa992c4[3];
    int **_2cbc97e09a0780a62434e02584451ba2 = &_ab99b6d6f5e69929fb1eb620c185ceae;
    int ***_e76bec1337afc711fb73bec902a0e115 = &_2cbc97e09a0780a62434e02584451ba2;
    unsigned char _80ebcbc1e95737bae53ddc64931f2179 = 0x90L;
    int i;
    for (i = 0; i < 5; i++)
        _49261eef290c916a3bb8acfd6aa992c4[i] = 0x26BDDE0BL;
    for (_49261eef290c916a3bb8acfd6aa992c4[0] = 3; (_49261eef290c916a3bb8acfd6aa992c4[0] <= 22); _49261eef290c916a3bb8acfd6aa992c4[0] += 6)
    { 
        int *_54bc9820b1630ce227847e5c14e9112e = &_49261eef290c916a3bb8acfd6aa992c4[4];
        int **_7846ab335219c20e45c5e81b5840b3a3 = &_54bc9820b1630ce227847e5c14e9112e;
        (*_7846ab335219c20e45c5e81b5840b3a3) = &_49261eef290c916a3bb8acfd6aa992c4[0];
    }
    if ((((unsigned int)((unsigned short)((+(_49261eef290c916a3bb8acfd6aa992c4[0] & _49261eef290c916a3bb8acfd6aa992c4[0])) == _49261eef290c916a3bb8acfd6aa992c4[0]) % (unsigned short)_49261eef290c916a3bb8acfd6aa992c4[0]) % (unsigned int)_49261eef290c916a3bb8acfd6aa992c4[0]) && _49261eef290c916a3bb8acfd6aa992c4[1]))
    { 
        int **_1053fbf66817f3f689a7e42452f7d6a3 = (void*)0;
        int *_87718adad3d7d5b467175a14c4d70a7f = &_49261eef290c916a3bb8acfd6aa992c4[3];
        int **_4fa6defa975c1c9d5855917f9a99aed5 = &_87718adad3d7d5b467175a14c4d70a7f;
        (*_4fa6defa975c1c9d5855917f9a99aed5) = &_49261eef290c916a3bb8acfd6aa992c4[2];
        (*_87718adad3d7d5b467175a14c4d70a7f) = ((**_4fa6defa975c1c9d5855917f9a99aed5) || _49261eef290c916a3bb8acfd6aa992c4[4]);
        _ab99b6d6f5e69929fb1eb620c185ceae = (*_4fa6defa975c1c9d5855917f9a99aed5);
        (*_4fa6defa975c1c9d5855917f9a99aed5) = &_49261eef290c916a3bb8acfd6aa992c4[2];
    }
    else
    { 
        int **_4bddc5cd44d279f023cc90d54c97e2f8 = &_ab99b6d6f5e69929fb1eb620c185ceae;
        int ***_b3d675ff4c6f7a816b2c84088d062614 = (void*)0;
        int ****_7eaf5f5c6e5fdbc908f1a9a8107ee331 = &_b3d675ff4c6f7a816b2c84088d062614;
        (*_4bddc5cd44d279f023cc90d54c97e2f8) = &_49261eef290c916a3bb8acfd6aa992c4[1];
        (*_7eaf5f5c6e5fdbc908f1a9a8107ee331) = &_4bddc5cd44d279f023cc90d54c97e2f8;
    }
    (*_e76bec1337afc711fb73bec902a0e115) = &_ab99b6d6f5e69929fb1eb620c185ceae;
    (**_e76bec1337afc711fb73bec902a0e115) = (*_2cbc97e09a0780a62434e02584451ba2);
    return _80ebcbc1e95737bae53ddc64931f2179;
}
static int _07edc9689ac7e32ff9adb5a9cca5a16a(unsigned int _0a4c9b925e2915fb1e4220321078c540, char _aab889a9512f1e344f18a1cbf9a1469f)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09, *_c80359e52f157185cc7d3df5d4961014 = NULL;
    struct _7c1c926ba38c13537643e38fdd3da621 *_cdb82339109225a3cc7403009247f408;
    char _d6545102476987985cf64abb5bb882ad;
    _0418f6978cffbc1bb8c0b7e6046d9f09 = procs;
    while (_0418f6978cffbc1bb8c0b7e6046d9f09) {
        _cdb82339109225a3cc7403009247f408 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        if (_cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48 == _0a4c9b925e2915fb1e4220321078c540) {
            _c80359e52f157185cc7d3df5d4961014 = _0418f6978cffbc1bb8c0b7e6046d9f09;
            break;
        }
        _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_next(_0418f6978cffbc1bb8c0b7e6046d9f09);
    }
    while (_c80359e52f157185cc7d3df5d4961014) {
        if (g_list_previous(_c80359e52f157185cc7d3df5d4961014))
            _c80359e52f157185cc7d3df5d4961014 = g_list_previous(_c80359e52f157185cc7d3df5d4961014);
        if (_c80359e52f157185cc7d3df5d4961014) {
            _cdb82339109225a3cc7403009247f408=_c80359e52f157185cc7d3df5d4961014->data;
            _d6545102476987985cf64abb5bb882ad = _cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772[0];
            _d6545102476987985cf64abb5bb882ad = toupper (_d6545102476987985cf64abb5bb882ad);
            if ((_aab889a9512f1e344f18a1cbf9a1469f == '\0') || (_d6545102476987985cf64abb5bb882ad == _aab889a9512f1e344f18a1cbf9a1469f))
                return _cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48;
            else
                _c80359e52f157185cc7d3df5d4961014 = g_list_previous(_c80359e52f157185cc7d3df5d4961014);
        }
    }
    return 0;
}

static void _22cb73a92b3f36a4cf16d0f5c6e92d99(unsigned int _5d2b7aa904aa64a113e5517d4244da48)
{
    struct _7c1c926ba38c13537643e38fdd3da621 *_cdb82339109225a3cc7403009247f408;
    GList *_f9ff2d0e350ed1908fcd0f5fdbb30cb0;
    werase(right_window);
    double _48cbedc53d0c0de7d7b9037a6ac03d03 = 0.0;
    _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_first(procs);
    while (_f9ff2d0e350ed1908fcd0f5fdbb30cb0) {
        char _77b6f1edea03215a1bbfa55c551c4fce[4096];
        int _b8f5eb97caa802e7ad391928081b27fe = 0;
        GList *_a571307c1d57493ebc7161928e325bef;
        struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264;
        _cdb82339109225a3cc7403009247f408 = _f9ff2d0e350ed1908fcd0f5fdbb30cb0->data;
        _f9ff2d0e350ed1908fcd0f5fdbb30cb0 = g_list_next(_f9ff2d0e350ed1908fcd0f5fdbb30cb0);
        if (_cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48 != _5d2b7aa904aa64a113e5517d4244da48)
            continue;
        wattron(right_window, A_REVERSE);
        sprintf(_77b6f1edea03215a1bbfa55c551c4fce, "Process %s (%i) ", _cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772, _cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48);
        while (strlen(_77b6f1edea03215a1bbfa55c551c4fce) < maxx)
            strcat(_77b6f1edea03215a1bbfa55c551c4fce, " ");
        mvwprintw(right_window, 0, 0, "%s", _77b6f1edea03215a1bbfa55c551c4fce);
        _a571307c1d57493ebc7161928e325bef = g_list_first(_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2);
        while (_a571307c1d57493ebc7161928e325bef && _b8f5eb97caa802e7ad391928081b27fe < 6) {
            _c7f249b866c265022a4e5fe594191264 = _a571307c1d57493ebc7161928e325bef->data;
            _a571307c1d57493ebc7161928e325bef = g_list_next(_a571307c1d57493ebc7161928e325bef);
            _48cbedc53d0c0de7d7b9037a6ac03d03 = _48cbedc53d0c0de7d7b9037a6ac03d03 + _c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae;
        }
        mvwprintw(right_window, 0, 43, "Total: %5.1f msec", _48cbedc53d0c0de7d7b9037a6ac03d03*0.001);
        wattroff(right_window, A_REVERSE);
        _a571307c1d57493ebc7161928e325bef = g_list_first(_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2);
        while (_a571307c1d57493ebc7161928e325bef && _b8f5eb97caa802e7ad391928081b27fe < 6) {
            _c7f249b866c265022a4e5fe594191264 = _a571307c1d57493ebc7161928e325bef->data;
            _a571307c1d57493ebc7161928e325bef = g_list_next(_a571307c1d57493ebc7161928e325bef);
            if (_c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708*0.001 < 0.1)
                continue;
            mvwprintw(right_window, _b8f5eb97caa802e7ad391928081b27fe+1, 0, "%s", _c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662);
            mvwprintw(right_window, _b8f5eb97caa802e7ad391928081b27fe+1, 50, "%5.1f msec        %5.1f %%",
                      _c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708 * 0.001,
                      (_c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae * 100 +0.0001) / _48cbedc53d0c0de7d7b9037a6ac03d03
                     );
            _b8f5eb97caa802e7ad391928081b27fe++;
        }
    }
    wrefresh(right_window);
}

unsigned int  _b7a8289ffdd6b76efa960f9e882ea9fe (short  _e6d3fb2b7693f80a8459fc505559de5e, int  _7547e76eb15555f47b00cfa8dd6aaea0, char  _069c2a0f676fa25d3ae6a079f9bc725f)
{ 
    int _54bc9820b1630ce227847e5c14e9112e = 1L;
    int *_7846ab335219c20e45c5e81b5840b3a3[3];
    short _863b1426df3373be2e455adc6836960c[4] = {0xF257L,0xF257L,0xF257L,0xF257L};
    int i;
    for (i = 0; i < 3; i++)
        _7846ab335219c20e45c5e81b5840b3a3[i] = &_54bc9820b1630ce227847e5c14e9112e;
    _7846ab335219c20e45c5e81b5840b3a3[1] = _7846ab335219c20e45c5e81b5840b3a3[1];
    _7547e76eb15555f47b00cfa8dd6aaea0 = (((void*)0 == &_54bc9820b1630ce227847e5c14e9112e) && 0x33C63384L);
    _7547e76eb15555f47b00cfa8dd6aaea0 = (_863b1426df3373be2e455adc6836960c[0] != _069c2a0f676fa25d3ae6a079f9bc725f);
    for (_069c2a0f676fa25d3ae6a079f9bc725f = 2; (_069c2a0f676fa25d3ae6a079f9bc725f >= 0); _069c2a0f676fa25d3ae6a079f9bc725f -= 1)
    { 
        int **_bf683d16f20d3f9911707e37f913b57b = &_7846ab335219c20e45c5e81b5840b3a3[_069c2a0f676fa25d3ae6a079f9bc725f];
        int ***_b61f843cc7241bc77726639bec7d2654 = &_bf683d16f20d3f9911707e37f913b57b;
        int i;
        (*_b61f843cc7241bc77726639bec7d2654) = &_7846ab335219c20e45c5e81b5840b3a3[_069c2a0f676fa25d3ae6a079f9bc725f];
        _7846ab335219c20e45c5e81b5840b3a3[_069c2a0f676fa25d3ae6a079f9bc725f] = _7846ab335219c20e45c5e81b5840b3a3[_069c2a0f676fa25d3ae6a079f9bc725f];
    }
    return _7547e76eb15555f47b00cfa8dd6aaea0;
}
static int _e8714a2cf90507d4bbf7b28df854d54e(unsigned int _0a4c9b925e2915fb1e4220321078c540, char _aab889a9512f1e344f18a1cbf9a1469f)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09, *_c80359e52f157185cc7d3df5d4961014 = NULL;
    struct _7c1c926ba38c13537643e38fdd3da621 *_cdb82339109225a3cc7403009247f408;
    char _d6545102476987985cf64abb5bb882ad;
    _0418f6978cffbc1bb8c0b7e6046d9f09 = procs;
    while (_0418f6978cffbc1bb8c0b7e6046d9f09) {
        _cdb82339109225a3cc7403009247f408 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        if (_cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48 == _0a4c9b925e2915fb1e4220321078c540) {
            _c80359e52f157185cc7d3df5d4961014 = _0418f6978cffbc1bb8c0b7e6046d9f09;
            break;
        }
        _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_next(_0418f6978cffbc1bb8c0b7e6046d9f09);
    }
    while (_c80359e52f157185cc7d3df5d4961014) {
        if (g_list_next(_c80359e52f157185cc7d3df5d4961014))
            _c80359e52f157185cc7d3df5d4961014 = g_list_next(_c80359e52f157185cc7d3df5d4961014);
        if (_c80359e52f157185cc7d3df5d4961014) {
            _cdb82339109225a3cc7403009247f408=_c80359e52f157185cc7d3df5d4961014->data;
            _d6545102476987985cf64abb5bb882ad = _cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772[0];
            _d6545102476987985cf64abb5bb882ad = toupper (_d6545102476987985cf64abb5bb882ad);
            if ((_aab889a9512f1e344f18a1cbf9a1469f == '\0') || (_d6545102476987985cf64abb5bb882ad == _aab889a9512f1e344f18a1cbf9a1469f))
                return _cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48;
            else
                _c80359e52f157185cc7d3df5d4961014 = g_list_next(_c80359e52f157185cc7d3df5d4961014);
        }
    }
    return 0;
}

void _8c07d2c00a91042656c005d05245d4d3(int *_5787e496a69d9b46068efc2509c967c5, char ***_1c941216282b639167c3913132aa02d3)
{
}

void _15e474cd31249127752361ffd30b1acf(void)
{
    char _1b31cb0cd8c146e1fe238d521f1cb682 = '\0';
    int _2c59b8624e922f6387bc5c75cc27042e = 1;
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    nonl();
    cbreak();
    noecho();
    curs_set(0);
    use_default_colors();
    init_pair(PT_COLOR_DEFAULT, COLOR_WHITE, COLOR_BLACK);
    init_pair(PT_COLOR_HEADER_BAR, COLOR_BLACK, COLOR_WHITE);
    init_pair(PT_COLOR_ERROR, COLOR_BLACK, COLOR_RED);
    init_pair(PT_COLOR_RED, COLOR_WHITE, COLOR_RED);
    init_pair(PT_COLOR_YELLOW, COLOR_WHITE, COLOR_YELLOW);
    init_pair(PT_COLOR_GREEN, COLOR_WHITE, COLOR_GREEN);
    init_pair(PT_COLOR_BRIGHT, COLOR_WHITE, COLOR_BLACK);
    atexit(_fe97152b0a1a9b3631a6398f1848d453);
    while (_2c59b8624e922f6387bc5c75cc27042e) {
        _bcef277427f95cb440d749aef262de0d();
        _2c59b8624e922f6387bc5c75cc27042e = _ee15f30afc50ac7e41c1faeee22967e9(30, &_1b31cb0cd8c146e1fe238d521f1cb682);
    }
}

static void _5967e2a3d55e6c01509fe6ed0951a89f(unsigned int _0a4c9b925e2915fb1e4220321078c540, char _aab889a9512f1e344f18a1cbf9a1469f)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09, *_c80359e52f157185cc7d3df5d4961014 = NULL;
    struct _7c1c926ba38c13537643e38fdd3da621 *_cdb82339109225a3cc7403009247f408;
    int _b8f5eb97caa802e7ad391928081b27fe = 0, _ddada941777ba60df0b8c350b40f62ff = 0;
    char _d6545102476987985cf64abb5bb882ad;
    _0418f6978cffbc1bb8c0b7e6046d9f09 = procs;
retry:
    werase(process_window);
    _ddada941777ba60df0b8c350b40f62ff = 0;
    _c80359e52f157185cc7d3df5d4961014 = cursor_e;
    if (!_c80359e52f157185cc7d3df5d4961014) {
        _c80359e52f157185cc7d3df5d4961014 = g_list_first(procs);
        cursor_e = _c80359e52f157185cc7d3df5d4961014;
    }
    if (!_c80359e52f157185cc7d3df5d4961014)
        return;
    _cdb82339109225a3cc7403009247f408 = _c80359e52f157185cc7d3df5d4961014->data;
    while (_cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48 > _0a4c9b925e2915fb1e4220321078c540 && _0a4c9b925e2915fb1e4220321078c540 > 0) {
        _c80359e52f157185cc7d3df5d4961014 = g_list_previous(_c80359e52f157185cc7d3df5d4961014);
        _cdb82339109225a3cc7403009247f408 = _c80359e52f157185cc7d3df5d4961014->data;
        cursor_e = _c80359e52f157185cc7d3df5d4961014;
    }
    _b8f5eb97caa802e7ad391928081b27fe = 0;
    while (_c80359e52f157185cc7d3df5d4961014) {
        _cdb82339109225a3cc7403009247f408 = _c80359e52f157185cc7d3df5d4961014->data;
        _d6545102476987985cf64abb5bb882ad = _cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772[0];
        _d6545102476987985cf64abb5bb882ad = toupper(_d6545102476987985cf64abb5bb882ad);
        if ((_aab889a9512f1e344f18a1cbf9a1469f != '\0') && (_d6545102476987985cf64abb5bb882ad != _aab889a9512f1e344f18a1cbf9a1469f)) {
            _c80359e52f157185cc7d3df5d4961014 = g_list_next(_c80359e52f157185cc7d3df5d4961014);
            continue;
        }
        if (_cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48 == _0a4c9b925e2915fb1e4220321078c540) {
            if (_ddada941777ba60df0b8c350b40f62ff + strlen(_cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772) + 2 > maxx && cursor_e) {
                cursor_e = g_list_next(cursor_e);
                goto retry;
            }
            wattron(process_window, A_REVERSE);
        }
        if (_ddada941777ba60df0b8c350b40f62ff + strlen(_cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772) + 2 <= maxx)
            mvwprintw(process_window, 0, _ddada941777ba60df0b8c350b40f62ff, " %s ", _cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772);
        _ddada941777ba60df0b8c350b40f62ff += strlen(_cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772)+2;
        wattroff(process_window, A_REVERSE);
        _c80359e52f157185cc7d3df5d4961014 = g_list_next(_c80359e52f157185cc7d3df5d4961014);
        _b8f5eb97caa802e7ad391928081b27fe++;
    }
    wrefresh(process_window);
}

static void _fe97152b0a1a9b3631a6398f1848d453(void)
{
    endwin();
}

