/* This file is part of RTags (https://github.com/Andersbakken/rtags).

   RTags is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   RTags is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with RTags.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef FindSymbolsJob_h
#define FindSymbolsJob_h

#include <memory>

#include "QueryJob.h"
#include "rct/String.h"

class QueryMessage;
class Project;

class FindSymbolsJob : public QueryJob
{
public:
    FindSymbolsJob(const std::shared_ptr<QueryMessage> &query, List<std::shared_ptr<Project>> &&project);

protected:
    virtual int execute() override;

private:
    const String string;
};

#endif
