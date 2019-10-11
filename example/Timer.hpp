/*
 * Copyright (C) 2017-2018 Trent Houliston <trent@houliston.me>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

/**
 * @brief Easily time events while removing the influence of the timer as much as possible
 *
 */
class Timer {
public:
  std::chrono::steady_clock::time_point t;

  Timer() : t(std::chrono::steady_clock::now()) {}

  template <size_t N>
  inline void measure(const char (&c)[N]) {

    // Work out how long it took
    auto end = std::chrono::steady_clock::now();
    auto val = end - t;
    auto v   = std::chrono::duration_cast<std::chrono::duration<uint64_t, std::micro>>(val).count();

    // Print out how many microseconds
    std::cout << c << " " << v << "µs" << std::endl;

    // Restart the timer
    t = std::chrono::steady_clock::now();
  }

  inline void reset() {
    // Restart the timer
    t = std::chrono::steady_clock::now();
  }
};

#endif  // TIMER_HPP
