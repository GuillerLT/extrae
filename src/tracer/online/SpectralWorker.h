/*****************************************************************************\
 *                        ANALYSIS PERFORMANCE TOOLS                         *
 *                                   Extrae                                  *
 *              Instrumentation package for parallel applications            *
 *****************************************************************************
 *     ___     This library is free software; you can redistribute it and/or *
 *    /  __         modify it under the terms of the GNU LGPL as published   *
 *   /  /  _____    by the Free Software Foundation; either version 2.1      *
 *  /  /  /     \   of the License, or (at your option) any later version.   *
 * (  (  ( B S C )                                                           *
 *  \  \  \_____/   This library is distributed in hope that it will be      *
 *   \  \__         useful but WITHOUT ANY WARRANTY; without even the        *
 *    \___          implied warranty of MERCHANTABILITY or FITNESS FOR A     *
 *                  PARTICULAR PURPOSE. See the GNU LGPL for more details.   *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public License  *
 * along with this library; if not, write to the Free Software Foundation,   *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA          *
 * The GNU LEsser General Public License is contained in the file COPYING.   *
 *                                 ---------                                 *
 *   Barcelona Supercomputing Center - Centro Nacional de Supercomputacion   *
\*****************************************************************************/

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- *\
 | @file: $HeadURL$
 | @last_commit: $Date$
 | @version:     $Revision$
\* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#ifndef __SPECTRAL_WORKER_H__
#define __SPECTRAL_WORKER_H__

#include <spectral-api.h>
#include "BackProtocol.h"
#include "Bursts.h"


class SpectralWorker : public BackProtocol
{
  public:
    string ID (void) { return "SPECTRAL"; } /* ID matches the front-end protocol */
    void Setup(void);
    int  Run  (void);

  private:
    STREAM *stSpectral;

    void ProcessPeriod(Bursts *AllBursts, Period_t *CurrentPeriod, int trace_this_period, int rep_period_id, unsigned long long PrevNonPeriodicZoneStartTime, unsigned long long &NextNonPeriodicZoneStartTime);
    void Trace_Period(Period_t *CurrentPeriod, unsigned long long *best_ini_out, unsigned long long *best_end_out);
    void New_Trace_Period(event_t *start, event_t *end);
};

#endif /* __SPECTRAL_WORKER_H__ */
