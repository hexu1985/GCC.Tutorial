### 预处理阶段

gcc编译器提供了一种模式，可以仅仅对输入文件执行预处理操作：

```
$ gcc -E <input file> -o <output preprocessed file>.i
```

对文件function.c执行与处理后的结果如下：

```
# 1 "function.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "function.c"
# 1 "function.h" 1
       







float add_and_multiply(float x, float y);
# 2 "function.c" 2

int nCompletionStatus = 0;

float add(float x, float y)
{
    float z = x + y;
    return z;
}

float add_and_multiply(float x, float y)
{
    float z = add(x,y);
    z *= (3.0);
    return z;
}
```

如果向gcc传递一些额外参数，我们就能够得到更为简洁明了的预处理输出结果，
比如增加以下参数：

```
$ gcc -E -P <input file> -o <output preprocessed file>.i
```

对文件function.c执行与处理后的结果如下：

```
float add_and_multiply(float x, float y);
int nCompletionStatus = 0;
float add(float x, float y)
{
    float z = x + y;
    return z;
}
float add_and_multiply(float x, float y)
{
    float z = add(x,y);
    z *= (3.0);
    return z;
}
```

因为头文件可能相当大，如果源文件包括了多个头文件，那么它的预处理器输出可能会庞杂难读。  
使用-C选项会很有帮助，这个选项可以阻止预处理器删除源文件和头文件中的注释：

```
$ gcc -E -C <input file> -o <output preprocessed file>.i
```

对文件function.c执行与处理后的结果如下：

```
# 1 "function.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4

# 1 "/usr/include/stdc-predef.h" 3 4
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */




/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */

/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
# 52 "/usr/include/stdc-predef.h" 3 4
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */


/* We do not support C11 <threads.h>.  */
# 32 "<command-line>" 2
# 1 "function.c"
# 1 "function.h" 1
       








# 9 "function.h"
float add_and_multiply(float x, float y);
# 2 "function.c" 2

int nCompletionStatus = 0;

float add(float x, float y)
{
    float z = x + y;
    return z;
}

float add_and_multiply(float x, float y)
{
    float z = add(x,y);
    z *= (3.0);
    return z;
}
```

#### 参考资料:
《高级C/C++编译技术》: 2.3.3 编译的各个阶段

