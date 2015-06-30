#ifndef MAIN_CTL_HANDLER_H
# define MAIN_CTL_HANDLER_H

#include <ctl.h>
#include <ev.h>

int ctl_handler_init(main_server_st* s);
void ctl_handler_deinit(main_server_st* s);

void ctl_handler_set_fds(main_server_st* s, ev_io *watcher);
void ctl_handler_run_pending(main_server_st* s, ev_io *watcher);

inline static void terminate_proc(main_server_st *s, proc_st *proc)
{
	/* if it has an IP, send a signal so that we cleanup
	 * and get stats properly */
	if (proc->pid != -1 && proc->pid != 0)
                kill(proc->pid, SIGTERM);
	else
		remove_proc(s, proc, RPROC_KILL);
}

#endif
