// This file is part of BOINC.
// http://boinc.berkeley.edu
// Copyright (C) 2010-2012 University of California
//
// BOINC is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// BOINC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with BOINC.  If not, see <http://www.gnu.org/licenses/>.

#define _VIRTUALBOX43_
#define _VIRTUALBOX_IMPORT_FUNCTIONS_

#include "boinc_win.h"
#include "win_util.h"
#include "diagnostics.h"
#include "filesys.h"
#include "parse.h"
#include "str_util.h"
#include "str_replace.h"
#include "util.h"
#include "error_numbers.h"
#include "procinfo.h"
#include "network.h"
#include "boinc_api.h"
#include "floppyio.h"
#include "vboxwrapper.h"
#include "vbox_mscom43.h"

#include "mscom43/VirtualBox.h"

#if defined(_MSC_VER) || defined(__MINGW32__)
#define stricmp     _stricmp
#endif

using std::string;
using namespace vbox43;

namespace vbox43 {

#include "mscom43/VirtualBox_i.c"

    class VBOX_PRIV {
    public:
        VBOX_PRIV() {};
        ~VBOX_PRIV() {};

        CComPtr<IVirtualBox> m_pVirtualBox;
        CComPtr<ISession> m_pSession;
        CComPtr<IMachine> m_pMachine;
    };

#include "vbox_mscom_impl.cpp"

}
