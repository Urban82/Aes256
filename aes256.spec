# Copyright (c) 2014, Danilo Treffiletti urban82@gmail.com
# All rights reserved.

# Aes256 is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 2.1 of the License, or (at your option) any later version.

# Aes256 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public License along with Aes256. If not, see http://www.gnu.org/licenses/.

# A copy of the license is included in the files COPYING and COPYING.LESSER.

%global _prefix /usr/local
%global SONAME aes256

Name:           Aes256
Version:        0.1
Release:        0%{?dist}
Summary:        AES 256 bit encryption and decryption
License:        LGPL-2.1
Group:          Productivity
Url:            https://github.com/Urban82/Aes256
Source0:        %{name}.tar.gz
BuildRequires:  cmake
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
BuildArch:      x86_64

%description
Aes256 is a library written in C++ that offer AES 256 bit encryption and decryption.

%package devel
Summary:        Header files and libraries for %{name}
Group:          Development/Libraries/C and C++
Requires:       lib%{SONAME} = %{version}

%description devel
The %{name}-devel package contains the header files and
libraries for aes256.

%package libs
Summary:        Shared library for %{name}
Group:          Productivity

%description libs
Shared library for %{name}.

%prep
%setup -n %{name}

%build
mkdir -p build && cd build && cmake ../ && make -j16

%install
cd build && make install DESTDIR=%{buildroot}

find %{buildroot} -type f -name '*.a' -delete

%post
# -n %{libname} -p /sbin/ldconfig

%postun
# -n %{libname} -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%doc COPYING README.md
%{_bindir}/encrypt
%{_bindir}/decrypt
#%attr(0755,root,root) %{_bindir}/*

%files devel
%defattr(-,root,root,-)
%{_includedir}/
%{_libdir}/lib%{SONAME}.so*

%files libs
%defattr(0755,root,root,0755)
%{_libdir}/lib%{SONAME}.so.*

%changelog

