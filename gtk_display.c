

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <dirent.h>
#include <time.h>
#include <wchar.h>
#include <ctype.h>
#include <assert.h>

#include <glib.h>
#include <gtk/gtk.h>

#include "latencytop.h"

static GtkWidget *main_window;
static GtkListStore *targets_model;
static GtkWidget *targets_view;
static GtkListStore *results_model;
static GtkWidget *results_view;
static GtkListStore *backtrace_model;
static GtkWidget *backtrace_view;
static GtkWidget *countdown_label;
static GtkWidget *freeze_button;

static GdkPixbuf *global_icon;
static GdkPixbuf *kthread_icon;
static GdkPixbuf *process_icon;

static unsigned int cur_target_pid;

static int countdown;
static int countdown_max = 30;
static int countdown_frozen;

static int ignore_sel;
static int force_results;


enum {
    COL_R_CAUSE = 0,
    COL_R_MAX,
    COL_R_PERCENT,
    COL_R_LINE
};

enum {
    COL_T_ICON = 0,
    COL_T_NAME,
    COL_T_MAX,
    COL_T_PROC,
};

enum {
    COL_B_FUNC = 0,
};

static void remove_all_targets(void)
{
    gtk_list_store_clear(targets_model);
}

static void remove_all_results(void)
{
    gtk_list_store_clear(results_model);
    gtk_list_store_clear(backtrace_model);
}

static gint compare_process(gconstpointer _8a99d69efbd0dc94c4ec664127be40ff, gconstpointer _c3f6279dce2f394e2256200c5d480538)
{
    const struct _7c1c926ba38c13537643e38fdd3da621 *pa = _8a99d69efbd0dc94c4ec664127be40ff;
    const struct _7c1c926ba38c13537643e38fdd3da621 *pb = _c3f6279dce2f394e2256200c5d480538;
    return pb->_659ed734ee9332662e8fad0e65088708 - pa->_659ed734ee9332662e8fad0e65088708;
}

static void insert_all_targets(void)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09;
    struct _7c1c926ba38c13537643e38fdd3da621 *_cdb82339109225a3cc7403009247f408;
    GtkTreeIter iter;
    gchar *esctext;
    GdkPixbuf *icon;
    GtkTreePath *path = NULL;
    int preferred;
    force_results = 1;
    gtk_list_store_append (GTK_LIST_STORE(targets_model), &iter);
    gtk_list_store_set (GTK_LIST_STORE(targets_model),
                        &iter,
                        COL_T_ICON, global_icon,
                        COL_T_NAME, "<b>Global</b>",
                        COL_T_MAX, "",
                        COL_T_PROC, NULL,
                        -1);
    if (cur_target_pid == 0)
        path = gtk_tree_model_get_path(GTK_TREE_MODEL(targets_model), &iter);
    _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_sort(procs, compare_process);
    while(_0418f6978cffbc1bb8c0b7e6046d9f09) {
        char targetstr[64];
        char maxstr[32];
        _cdb82339109225a3cc7403009247f408 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_next(_0418f6978cffbc1bb8c0b7e6046d9f09);
        preferred = _cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772 && prefered_process &&
                    strcmp(_cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772, prefered_process) == 0;
        if (!preferred && (_cdb82339109225a3cc7403009247f408->_659ed734ee9332662e8fad0e65088708 * 0.001 < 0.1))
            continue;
        if (preferred)
            gtk_list_store_insert(GTK_LIST_STORE(targets_model), &iter, 1);
        else
            gtk_list_store_append(GTK_LIST_STORE(targets_model), &iter);
        esctext = g_markup_escape_text(_cdb82339109225a3cc7403009247f408->_f3dc173b71df4a4441481159de629772, -1);
        icon = _cdb82339109225a3cc7403009247f408->_bff4bf7f1a92beb69a16a1f00427d649 ? kthread_icon : process_icon;
        sprintf(maxstr, "%.1f", _cdb82339109225a3cc7403009247f408->_659ed734ee9332662e8fad0e65088708 * 0.001);
        targetstr[63] = 0;
        if (preferred)
            snprintf(targetstr, 63, "<u>%s</u>", esctext);
        else
            strncpy(targetstr, esctext, 63);
        gtk_list_store_set(GTK_LIST_STORE(targets_model),
                           &iter,
                           COL_T_ICON, icon,
                           COL_T_NAME, targetstr,
                           COL_T_MAX, maxstr,
                           COL_T_PROC, _cdb82339109225a3cc7403009247f408,
                           -1);
        if (cur_target_pid == _cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48)
            path = gtk_tree_model_get_path(GTK_TREE_MODEL(targets_model), &iter);
        g_free(esctext);
    }
    if (path)
        gtk_tree_view_set_cursor(GTK_TREE_VIEW(targets_view),
                                 path, NULL, FALSE);
}

static void insert_results(GList *list)
{
    GList *_0418f6978cffbc1bb8c0b7e6046d9f09;
    struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264;
    GtkTreeIter iter;
    gchar *reasonstr;
    int l;
    _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_first(list);
    while(_0418f6978cffbc1bb8c0b7e6046d9f09) {
        char maxstr[32];
        char percentstr[32];
        _c7f249b866c265022a4e5fe594191264 = _0418f6978cffbc1bb8c0b7e6046d9f09->data;
        _0418f6978cffbc1bb8c0b7e6046d9f09 = g_list_next(_0418f6978cffbc1bb8c0b7e6046d9f09);
        if (_c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708 * 0.001 < 0.1)
            continue;
        reasonstr = g_strdup(_c7f249b866c265022a4e5fe594191264->_4bb1fc391d3e7f0518b93953fac3e662);
        l = strlen(reasonstr);
        while(l) {
            if (reasonstr[--l] != '\n')
                break;
            reasonstr[l] = 0;
        }
        gtk_list_store_append(GTK_LIST_STORE(results_model), &iter);
        sprintf(maxstr, "%.1f ms", _c7f249b866c265022a4e5fe594191264->_659ed734ee9332662e8fad0e65088708 * 0.001);
        sprintf(percentstr, "%.1f %%", (_c7f249b866c265022a4e5fe594191264->_495433b372d36b65f5a7d696c149d3ae * 100 + 0.0001) / total_time);
        gtk_list_store_set(GTK_LIST_STORE(results_model),
                           &iter,
                           COL_R_CAUSE, reasonstr,
                           COL_R_MAX, maxstr,
                           COL_R_PERCENT, percentstr,
                           COL_R_LINE, _c7f249b866c265022a4e5fe594191264,
                           -1);
        g_free(reasonstr);
    }
}

static void insert_backtrace(struct _6f34563b4786566596c745dad8985e7d *_c7f249b866c265022a4e5fe594191264)
{
    GtkTreeIter iter;
    char *_c196aecd0568cc09c8c913c499c7cb41 = _c7f249b866c265022a4e5fe594191264->_93b17948fde849068f5b4c774be446ca;
    char *_2f867812bfe6f338d720c03e5920ef9d;
    char _4f71fb17aeb37e4a724a9741a6536aa6[1024];
    while (_c196aecd0568cc09c8c913c499c7cb41 && *_c196aecd0568cc09c8c913c499c7cb41) {
        while (*_c196aecd0568cc09c8c913c499c7cb41 == ' ')
            _c196aecd0568cc09c8c913c499c7cb41++;
        if (!*_c196aecd0568cc09c8c913c499c7cb41)
            break;
        _2f867812bfe6f338d720c03e5920ef9d = strchr(_c196aecd0568cc09c8c913c499c7cb41, ' ');
        if (_2f867812bfe6f338d720c03e5920ef9d) {
            int l = MIN(_2f867812bfe6f338d720c03e5920ef9d-_c196aecd0568cc09c8c913c499c7cb41, 1023);
            strncpy(_4f71fb17aeb37e4a724a9741a6536aa6, _c196aecd0568cc09c8c913c499c7cb41, l);
            _4f71fb17aeb37e4a724a9741a6536aa6[l] = 0;
        } else {
            strncpy(_4f71fb17aeb37e4a724a9741a6536aa6, _c196aecd0568cc09c8c913c499c7cb41, 1023);
            _4f71fb17aeb37e4a724a9741a6536aa6[1023] = 0;
        }
        _c196aecd0568cc09c8c913c499c7cb41 = _2f867812bfe6f338d720c03e5920ef9d;
        gtk_list_store_append(GTK_LIST_STORE(backtrace_model), &iter);
        gtk_list_store_set(GTK_LIST_STORE(backtrace_model),
                           &iter,
                           COL_B_FUNC, _4f71fb17aeb37e4a724a9741a6536aa6,
                           -1);
    }
    gtk_tree_view_columns_autosize(GTK_TREE_VIEW(backtrace_view));
}

static gint target_select(GtkTreeSelection *sel, void *data)
{
    GtkTreeModel		*model;
    GtkTreeIter		iter;
    struct _7c1c926ba38c13537643e38fdd3da621		*_cdb82339109225a3cc7403009247f408 = NULL;
    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(targets_view));
    if (gtk_tree_selection_get_selected(sel, &model, &iter))
        gtk_tree_model_get(model, &iter, COL_T_PROC, &_cdb82339109225a3cc7403009247f408, -1);
    if (ignore_sel)
        return TRUE;
    if (_cdb82339109225a3cc7403009247f408 && (force_results || _cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48 != cur_target_pid)) {
        cur_target_pid = _cdb82339109225a3cc7403009247f408->_5d2b7aa904aa64a113e5517d4244da48;
        remove_all_results();
        insert_results(_cdb82339109225a3cc7403009247f408->_015d69ff182a558e9cea665fff9fbec2);
    } else if (!_cdb82339109225a3cc7403009247f408 && (force_results || cur_target_pid != 0)) {
        cur_target_pid = 0;
        remove_all_results();
        insert_results(lines);
    }
    force_results = 0;
    return FALSE;
}

static gint backtrace_select(GtkTreeSelection *sel, void *data)
{
    GtkTreeModel		*model;
    GtkTreeIter		iter;
    struct _6f34563b4786566596c745dad8985e7d	*_c7f249b866c265022a4e5fe594191264 = NULL;
    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(results_view));
    if (gtk_tree_selection_get_selected(sel, &model, &iter))
        gtk_tree_model_get(model, &iter, COL_R_LINE, &_c7f249b866c265022a4e5fe594191264, -1);
    if (ignore_sel)
        return TRUE;
    gtk_list_store_clear(backtrace_model);
    if (_c7f249b866c265022a4e5fe594191264)
        insert_backtrace(_c7f249b866c265022a4e5fe594191264);
    return TRUE;
}

static void do_refresh(void)
{
    ignore_sel = TRUE;
    remove_all_targets();
    remove_all_results();
    _bcef277427f95cb440d749aef262de0d();
    ignore_sel = FALSE;
    insert_all_targets();
    gtk_tree_view_columns_autosize(GTK_TREE_VIEW(targets_view));
    gtk_tree_view_columns_autosize(GTK_TREE_VIEW(results_view));
}

static void update_countdown(void)
{
    char _4f71fb17aeb37e4a724a9741a6536aa6[128];
    sprintf(_4f71fb17aeb37e4a724a9741a6536aa6, "Refresh in %d s", countdown);
    gtk_label_set_text(GTK_LABEL(countdown_label), _4f71fb17aeb37e4a724a9741a6536aa6);
}

static gint timer_tick(void *data)
{
    if (countdown_frozen)
        return TRUE;
    countdown--;
    if (countdown <= 0) {
        countdown = countdown_max;
        do_refresh();
    }
    update_countdown();
    return TRUE;
}

static void refresh_clicked(GtkButton *btn, void *data)
{
    do_refresh();
    countdown = countdown_max;
    update_countdown();
}

static void freeze_toggled(GtkToggleButton *btn, void *data)
{
    gboolean state = gtk_toggle_button_get_active(btn);
    countdown_frozen = state;
}

static GtkWidget *create_targets_list(void)
{
    GtkWidget *scrollw;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeSelection *sel;
    scrollw = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollw),
                                   GTK_POLICY_AUTOMATIC,
                                   GTK_POLICY_AUTOMATIC);
    targets_view = gtk_tree_view_new();
    gtk_container_add(GTK_CONTAINER(scrollw), targets_view);
    targets_model = gtk_list_store_new(4,
                                       GDK_TYPE_PIXBUF,
                                       G_TYPE_STRING,
                                       G_TYPE_STRING,
                                       G_TYPE_POINTER);
    gtk_tree_view_set_model(GTK_TREE_VIEW(targets_view),
                            GTK_TREE_MODEL(targets_model));
    column = gtk_tree_view_column_new();
    gtk_tree_view_column_set_title(column, "Targets");
    renderer = gtk_cell_renderer_pixbuf_new();
    gtk_tree_view_column_pack_start(column, renderer, FALSE);
    gtk_tree_view_column_set_attributes(column, renderer,
                                        "pixbuf", COL_T_ICON,
                                        NULL);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(column, renderer, TRUE);
    gtk_tree_view_column_set_attributes(column, renderer,
                                        "markup", COL_T_NAME,
                                        NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(targets_view),
                                GTK_TREE_VIEW_COLUMN(column));
    renderer = gtk_cell_renderer_text_new();
    g_object_set(G_OBJECT(renderer),
                 "xalign", 1.0,
                 NULL);
    column = gtk_tree_view_column_new_with_attributes("Max",
             renderer,
             "text", COL_T_MAX,
             NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(targets_view),
                                GTK_TREE_VIEW_COLUMN(column));
    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(targets_view));
    gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
    g_signal_connect(G_OBJECT(sel), "changed",
                     G_CALLBACK(target_select), NULL);
    return scrollw;
}

static GtkWidget *create_results_list(void)
{
    GtkWidget *scrollw;
    GtkCellRenderer *cell;
    GtkTreeViewColumn *column;
    GtkTreeSelection *sel;
    scrollw = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (scrollw),
                                   GTK_POLICY_AUTOMATIC,
                                   GTK_POLICY_AUTOMATIC);
    results_view = gtk_tree_view_new();
    gtk_container_add(GTK_CONTAINER(scrollw), results_view);
    results_model = gtk_list_store_new(4,
                                       G_TYPE_STRING,
                                       G_TYPE_STRING,
                                       G_TYPE_STRING,
                                       G_TYPE_POINTER);
    gtk_tree_view_set_model(GTK_TREE_VIEW(results_view),
                            GTK_TREE_MODEL(results_model));
    cell = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("Cause",
             cell,
             "text", COL_R_CAUSE,
             NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(results_view),
                                GTK_TREE_VIEW_COLUMN(column));
    cell = gtk_cell_renderer_text_new ();
    g_object_set(G_OBJECT(cell),
                 "xalign", 1.0,
                 NULL);
    column = gtk_tree_view_column_new_with_attributes ("Maximum",
             cell,
             "text", COL_R_MAX,
             NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(results_view),
                                GTK_TREE_VIEW_COLUMN(column));
    cell = gtk_cell_renderer_text_new ();
    g_object_set(G_OBJECT(cell),
                 "xalign", 1.0,
                 NULL);
    column = gtk_tree_view_column_new_with_attributes ("Percentage",
             cell,
             "text", COL_R_PERCENT,
             NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(results_view),
                                GTK_TREE_VIEW_COLUMN(column));
    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(results_view));
    gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
    g_signal_connect(G_OBJECT(sel), "changed",
                     G_CALLBACK(backtrace_select), NULL);
    return scrollw;
}

static GtkWidget *create_backtrace_list(void)
{
    GtkWidget *scrollw;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeSelection *sel;
    scrollw = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollw),
                                   GTK_POLICY_AUTOMATIC,
                                   GTK_POLICY_AUTOMATIC);
    backtrace_view = gtk_tree_view_new();
    gtk_container_add(GTK_CONTAINER(scrollw), backtrace_view);
    backtrace_model = gtk_list_store_new(1, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(backtrace_view),
                            GTK_TREE_MODEL(backtrace_model));
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("Backtrace",
             renderer,
             "text", COL_B_FUNC,
             NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(backtrace_view),
                                GTK_TREE_VIEW_COLUMN(column));
    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(backtrace_view));
    gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
    return scrollw;
}

static void create_targets_window(void)
{
    GtkWidget *w, *paned, *paned2, *vbox, *hbox, *btn;
    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "LatencyTOP "VERSION);
    g_signal_connect(G_OBJECT(main_window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(main_window), 5);
    gtk_widget_set_size_request(main_window, 600, 400);
    vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(main_window), vbox);
    paned = gtk_hpaned_new();
    gtk_box_pack_start(GTK_BOX(vbox), paned, TRUE, TRUE, 0);
    w = create_targets_list();
    gtk_paned_add1(GTK_PANED(paned), w);
    paned2 = gtk_vpaned_new();
    gtk_paned_add2(GTK_PANED(paned), paned2);
    w = create_results_list();
    gtk_paned_add1(GTK_PANED(paned2), w);
    w = create_backtrace_list();
    gtk_paned_add2(GTK_PANED(paned2), w);
    gtk_paned_set_position(GTK_PANED(paned), 200);
    gtk_paned_set_position(GTK_PANED(paned2), 250);
    hbox = gtk_hbox_new(FALSE, 5);
    gtk_box_pack_end(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
    countdown_label = gtk_label_new("");
    gtk_box_pack_end(GTK_BOX(hbox), countdown_label, FALSE, FALSE, 0);
    btn = gtk_button_new_with_label("Refresh");
    gtk_box_pack_end(GTK_BOX(hbox), btn, FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(btn), "clicked",
                     G_CALLBACK(refresh_clicked), NULL);
    freeze_button = gtk_toggle_button_new_with_label("Freeze");
    gtk_box_pack_end(GTK_BOX(hbox), freeze_button, FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(freeze_button), "toggled",
                     G_CALLBACK(freeze_toggled), NULL);
}

static load_icons(void)
{
    GError *err;
#define ICON_SIZE	18
#define PATH_PREFIX	"/usr/share/latencytop/"
    err = NULL;
    global_icon = gdk_pixbuf_new_from_file_at_size(PATH_PREFIX "global.png",
                  ICON_SIZE, ICON_SIZE,
                  &err);
    if (!global_icon) {
        err = NULL;
        global_icon = gdk_pixbuf_new_from_file_at_size("global.png",
                      ICON_SIZE, ICON_SIZE,
                      &err);
    }
    err = NULL;
    kthread_icon = gdk_pixbuf_new_from_file_at_size(PATH_PREFIX "kernel_thread.png",
                   ICON_SIZE, ICON_SIZE,
                   &err);
    if (!kthread_icon) {
        err = NULL;
        kthread_icon = gdk_pixbuf_new_from_file_at_size("kernel_thread.png",
                       ICON_SIZE, ICON_SIZE,
                       &err);
    }
    err = NULL;
    process_icon = gdk_pixbuf_new_from_file_at_size(PATH_PREFIX "user_process.png",
                   ICON_SIZE, ICON_SIZE, &err);
    if (!process_icon) {
        err = NULL;
        process_icon = gdk_pixbuf_new_from_file_at_size("user_process.png",
                       ICON_SIZE, ICON_SIZE,
                       &err);
    }
}

void start_gtk_ui(void)
{
    load_icons();
    create_targets_window();
    _bcef277427f95cb440d749aef262de0d();
    insert_all_targets();
    gtk_tree_view_columns_autosize(GTK_TREE_VIEW(targets_view));
    gtk_tree_view_columns_autosize(GTK_TREE_VIEW(results_view));
    gtk_widget_show_all(main_window);
    countdown = countdown_max;
    update_countdown();
    g_timeout_add(1000, timer_tick, NULL);
    gtk_main();
}

int preinitialize_gtk_ui(int *_5787e496a69d9b46068efc2509c967c5, char ***_1c941216282b639167c3913132aa02d3)
{
    int rc, _b8f5eb97caa802e7ad391928081b27fe;
    rc = gtk_init_check(_5787e496a69d9b46068efc2509c967c5, _1c941216282b639167c3913132aa02d3);
    if (!rc)
        return FALSE;
    for (_b8f5eb97caa802e7ad391928081b27fe = 1; _b8f5eb97caa802e7ad391928081b27fe < *_5787e496a69d9b46068efc2509c967c5; _b8f5eb97caa802e7ad391928081b27fe++)
        if (strcmp((*_1c941216282b639167c3913132aa02d3)[_b8f5eb97caa802e7ad391928081b27fe], "--nogui") == 0)
            return FALSE;
    return TRUE;
}

