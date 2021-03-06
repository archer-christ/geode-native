#pragma once

#ifndef GEODE_STATISTICS_WINDOWSPROCESSSTATS_H_
#define GEODE_STATISTICS_WINDOWSPROCESSSTATS_H_

/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <gfcpp/gfcpp_globals.hpp>
#include <gfcpp/statistics/Statistics.hpp>
#include <gfcpp/statistics/StatisticsType.hpp>
#include <gfcpp/statistics/StatisticDescriptor.hpp>
#include <gfcpp/statistics/StatisticsFactory.hpp>
#include "ProcessStats.hpp"
#include <gfcpp/ExceptionTypes.hpp>

using namespace apache::geode::client;

/** @file
*/

namespace apache {
namespace geode {
namespace statistics {
/**
 * <P>This class provides the interface for statistics about a
 * Windows operating system process that is using a Geode system.
 */

class CPPCACHE_EXPORT WindowsProcessStats : public ProcessStats {
 private:
  /** The Static Type for Windows Process Stats */
  StatisticsType* m_statsType;

  /** Ids of All Stats Desciptors for seting new values */
  int32 handlesINT;
  int32 priorityBaseINT;
  int32 threadsINT;
  int32 activeTimeLONG;
  int32 pageFaultsLONG;
  int32 pageFileSizeLONG;
  int32 pageFileSizePeakLONG;
  int32 privateSizeLONG;
  int32 systemTimeLONG;
  int32 userTimeLONG;
  int32 virtualSizeLONG;
  int32 virtualSizePeakLONG;
  int32 workingSetSizeLONG;
  int32 workingSetSizePeakLONG;
  int32 cpuUsageINT;

  /** The underlying statistics */
  Statistics* stats;

  void createType(StatisticsFactory* statFactory);

 public:
  WindowsProcessStats(int64 pid, const char* name);
  ~WindowsProcessStats();

  int64 getProcessSize();
  int32 getCpuUsage();
  int64 getCPUTime();
  int32 getNumThreads();
  int64 getAllCpuTime();
  /**
   * Close Underline Statistics
   */
  void close();

  friend class HostStatHelperWin;
};
}  // namespace client
}  // namespace geode
}  // namespace apache

#endif // GEODE_STATISTICS_WINDOWSPROCESSSTATS_H_
