%define api 0.0

Name:           libzapojit
Version:        0.0.3
Release:        4%{?dist}
Summary:        GLib/GObject wrapper for the SkyDrive and Hotmail REST APIs

License:        LGPLv2+
URL:            http://live.gnome.org/Zapojit
Source0:        http://download.gnome.org/sources/%{name}/%{api}/%{name}-%{version}.tar.xz

BuildRequires:  gettext
BuildRequires:  glib2-devel >= 2.28
BuildRequires:  gnome-online-accounts-devel
BuildRequires:  gobject-introspection-devel
BuildRequires:  gtk-doc
BuildRequires:  intltool
BuildRequires:  json-glib-devel
BuildRequires:  libsoup-devel >= 2.38
BuildRequires:  libtool
BuildRequires:  pkgconfig
BuildRequires:  rest-devel
Requires:       gobject-introspection

%description
GLib/GObject wrapper for the SkyDrive and Hotmail REST APIs. It supports
SkyDrive file and folder objects, and the following SkyDrive operations:
  - Deleting a file, folder or photo.
  - Listing the contents of a folder.
  - Reading the properties of a file, folder or photo.
  - Uploading files and photos.

%package        devel
Summary:        Development files for %{name}
Requires:       gobject-introspection-devel
Requires:       %{name}%{?_isa} = %{version}-%{release}
Requires:       pkgconfig

%description    devel
The %{name}-devel package contains libraries and header files for
developing applications that use %{name}.


%prep
%setup -q


%build
%configure \
  --disable-silent-rules \
  --disable-static \
  --enable-gtk-doc \
  --enable-introspection

# Omit unused direct shared library dependencies.
sed --in-place --expression 's! -shared ! -Wl,--as-needed\0!g' libtool

make %{?_smp_mflags}


%install
make install INSTALL="%{__install} -p" DESTDIR=$RPM_BUILD_ROOT

find $RPM_BUILD_ROOT -name '*.la' -delete
rm -rf $RPM_BUILD_ROOT%{_datadir}/doc/%{name}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%doc AUTHORS
%doc COPYING
%doc ChangeLog
%doc NEWS
%doc README
%{_libdir}/%{name}-%{api}.so.*

%dir %{_libdir}/girepository-1.0
%{_libdir}/girepository-1.0/Zpj-%{api}.typelib

%files devel
%{_libdir}/%{name}-%{api}.so
%{_libdir}/pkgconfig/zapojit-%{api}.pc

%dir %{_datadir}/gir-1.0
%{_datadir}/gir-1.0/Zpj-%{api}.gir

%dir %{_datadir}/gtk-doc
%dir %{_datadir}/gtk-doc/html
%doc %{_datadir}/gtk-doc/html/%{name}-%{api}

%dir %{_includedir}/%{name}-%{api}
%{_includedir}/%{name}-%{api}/zpj


%changelog
* Fri Jan 24 2014 Daniel Mach <dmach@redhat.com> - 0.0.3-4
- Mass rebuild 2014-01-24

* Fri Dec 27 2013 Daniel Mach <dmach@redhat.com> - 0.0.3-3
- Mass rebuild 2013-12-27

* Tue Jul 16 2013 Matthias Clasen <mclasen@redhat.com> - 0.0.3-2
- Rebuild with newer gtk-doc to fix multilib issues

* Fri Mar 08 2013 Debarshi Ray <rishi@fedoraproject.org> - 0.0.3-1
- Update to 0.0.3.

* Thu Feb 14 2013 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 0.0.2-4
- Rebuilt for https://fedoraproject.org/wiki/Fedora_19_Mass_Rebuild

* Thu Jul 19 2012 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 0.0.2-3
- Rebuilt for https://fedoraproject.org/wiki/Fedora_18_Mass_Rebuild

* Fri Jun 08 2012 Debarshi Ray <rishi@fedoraproject.org> - 0.0.2-2
- Co-own %%{_libdir}/girepository-1.0 and %%{_datadir}/gir-1.0.
- Remove Group tag and %%defattr.

* Wed Jun 06 2012 Debarshi Ray <rishi@fedoraproject.org> - 0.0.2-1
- Update to 0.0.2.

* Wed May 30 2012 Debarshi Ray <rishi@fedoraproject.org> - 0.0.1-1
- Initial spec.
