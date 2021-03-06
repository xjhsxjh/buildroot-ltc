// Copyright (C) 2016 InfoTM, yong.yan@infotm.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <System.h>
#include "PP.h"

int IPU_PP::UnitControl(std::string func, void *arg)
{

    LOGD("%s: %s\n", __func__, func.c_str());

    UCSet(func);

    UCFunction(video_set_pip_info) {
        SetPipInfo((struct v_pip_info *)arg);
        return 0;
    }

    UCFunction(video_get_pip_info) {
        GetPipInfo((struct v_pip_info *)arg);
        return 0;
    }

    LOGE("%s is not support\n", func.c_str());
    return VBENOFUNC;
}
