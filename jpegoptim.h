/* jpegoptim.h
 *
 * JPEGoptim headers
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * This file is part of JPEGoptim.
 *
 * JPEGoptim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * JPEGoptim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with JPEGoptim. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef JPEGOPTIM_H
#define JPEGOPTIM_H 1

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef WIN32
#include "win32_compat.h"
#define DIR_SEPARATOR_C '\\'
#define DIR_SEPARATOR_S "\\"
#else
#include <sys/param.h>
#include <utime.h>
#define DIR_SEPARATOR_C '/'
#define DIR_SEPARATOR_S "/"
#define set_filemode_binary(file) {}
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <jpeglib.h>

#ifdef BROKEN_METHODDEF
#undef METHODDEF
#define METHODDEF(x) static x
#endif

#ifndef HAVE_LABS
#define labs abs
#endif

#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#endif

#define JFIF_JPEG_MARKER  JPEG_APP0
#define JFIF_IDENT_STRING "JFIF\0"
#define JFIF_IDENT_STRING_SIZE 5

#define JFXX_JPEG_MARKER  JPEG_APP0
#define JFXX_IDENT_STRING "JFXX\0"
#define JFXX_IDENT_STRING_SIZE 5

#define EXIF_JPEG_MARKER   JPEG_APP0 + 1
#define EXIF_IDENT_STRING  "Exif\000\000"
#define EXIF_IDENT_STRING_SIZE 6

#define IPTC_JPEG_MARKER   JPEG_APP0 + 13

#define ICC_JPEG_MARKER   JPEG_APP0 + 2
#define ICC_IDENT_STRING  "ICC_PROFILE\0"
#define ICC_IDENT_STRING_SIZE 12

#define XMP_JPEG_MARKER   JPEG_APP0 + 1
#define XMP_IDENT_STRING  "http://ns.adobe.com/xap/1.0/\000"
#define XMP_IDENT_STRING_SIZE 29

#define ADOBE_JPEG_MARKER JPEG_APP0 + 14
#define ADOBE_IDENT_STRING "Adobe"
#define ADOBE_IDENT_STRING_SIZE 5


#define PROGRAMNAME "jpegoptim"

extern int verbose_mode;
extern int quiet_mode;



/* misc.c */
int delete_file(const char *name);
long file_size(FILE *fp);
int is_directory(const char *path);
int is_file(const char *filename, struct stat *st);
int file_exists(const char *pathname);
int rename_file(const char *old_path, const char *new_path);
int copy_file(const char *srcname, const char *dstname);
char *splitdir(const char *pathname, char *buf, int buflen);
char *splitname(const char *pathname, char *buf, int buflen);
void fatal(const char *format, ...);
void warn(const char *format, ...);


/* jpegdest.c */
void jpeg_memory_dest (j_compress_ptr cinfo, unsigned char **bufptr,
		size_t *bufsizeptr, size_t incsize);

/* jpegsrc.c */
void jpeg_custom_src(j_decompress_ptr dinfo, FILE *infile,
		unsigned char **bufptr,	size_t *bufsizeptr, size_t *bufusedptr, size_t incsize);




#ifdef	__cplusplus
}
#endif

#endif /* JPEGOPTIM_H */
