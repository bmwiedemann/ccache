// Copyright (C) 2022 Joel Rosdahl and other contributors
//
// See doc/AUTHORS.adoc for a complete list of contributors.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#pragma once

#include <atomic>
#include <cstdint>
#include <mutex>
#include <optional>
#include <string>

namespace core {

class FileRecompressor
{
public:
  FileRecompressor() = default;

  // Returns on-disk size change in KiB.
  int64_t recompress(const std::string& cache_file,
                     const std::optional<int8_t> level);

  uint64_t content_size() const;
  uint64_t old_size() const;
  uint64_t new_size() const;

private:
  std::atomic<uint64_t> m_content_size = 0;
  std::atomic<uint64_t> m_old_size = 0;
  std::atomic<uint64_t> m_new_size = 0;
};

} // namespace core
