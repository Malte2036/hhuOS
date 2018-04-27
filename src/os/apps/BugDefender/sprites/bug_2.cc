/*
 * Copyright (C) 2018  Filip Krakowski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[30 * 20 * 4 + 1];
} bug_2 = {
  30, 20, 4,
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\325\325\325\006\331\333\333\224\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\331\333\333\224\314\314\314\005\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\326\326\336\037\331\331\333\201"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\331\333\333\232\325\337\337\030\277\277\277"
  "\004\334\334\334$\334\334\334$\277\277\277\004\326\326\326\031\331\333\333\232"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\331\331\333\201\335\335\335\036\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333"
  "\333\333\025\330\332\334\212\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\343\343\343\011"
  "\332\332\332n\331\332\333\344\331\332\333\377\331\332\333\377\331\332\333"
  "\343\332\332\332m\343\343\343\011\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\330\332"
  "\332\213\331\331\331\024\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\325\325\325\014\331\333\333\223\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\331\332\333\351\331\332\333\377\331\332\333"
  "\377\331\332\333\377\331\332\333\377\331\332\333\351\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\331\333\333\224\321\321\321\013\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\377\377\377\003"
  "\331\331\333\234\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\330\330\334v\330"
  "\334\334\212\331\333\333\223\331\333\333\223\330\334\334\212\330\330\335"
  "w\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\332\332\333\235\377\377\377\003\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\331\333\333\177\330\332\332h\331\331\331\024\000\000\000\000\330\334"
  "\334H\332\332\333\314\331\332\333\377\331\332\333\377\331\332\333\377\331"
  "\332\333\377\331\332\333\377\331\332\333\377\332\332\333\314\327\333\333"
  "G\000\000\000\000\331\331\331\024\330\332\332h\331\333\333\177\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\325\325\325\014\325\343\343\022\331\331\334W\331\333\333\313\332"
  "\332\333\314\332\332\333\314\332\332\333\314\332\332\333\314\332\332\333"
  "\314\332\332\333\314\332\332\333\314\332\332\333\314\331\333\333\313\331"
  "\331\334X\325\343\343\022\325\325\325\014\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\330\333\333p\331\332\333\377\331\332\333\377\331\332\333\377"
  "\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332"
  "\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377"
  "\332\332\332n\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\335\335\335"
  "\017\331\332\333\361\331\332\333\377\331\332\333\377\331\332\333\377\331\332"
  "\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377"
  "\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332"
  "\333\360\333\333\333\016\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\377\377\377\003\322\341\341\021\334\334\334\026"
  "\333\333\333\034\332\332\332R\331\332\333\377\331\332\333\377\331\332\333"
  "\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331"
  "\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333"
  "\377\331\332\333\377\331\332\333\377\331\331\334P\333\333\333\034\334\334"
  "\334\026\322\341\341\021\377\377\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\332\332\332E\331\331\333\216\327\333\333G\333\333\333\071\330"
  "\333\333i\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377"
  "\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332"
  "\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377"
  "\331\332\333\377\330\333\333i\333\333\333\071\327\333\333G\331\331\333\216"
  "\332\332\332E\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\331\331\333"
  "k\331\331\331\066\000\000\000\000\000\000\000\000\332\332\332L\331\332\333\377\331\332\333"
  "\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331"
  "\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333"
  "\377\331\332\333\377\331\332\333\377\331\332\333\377\331\331\335J\000\000\000\000"
  "\000\000\000\000\332\332\332\067\331\333\333j\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\330\332\334\227\322\341\341\021\000\000\000\000\000\000\000\000\330\330\330\015"
  "\331\332\333\355\331\332\333\377\331\332\333\377\331\332\333\377\331\332"
  "\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377"
  "\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332"
  "\333\354\325\325\325\014\000\000\000\000\000\000\000\000\322\341\341\021\330\332\334\227\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\314\314\314\005\332\332\332u\332\332\332K\000"
  "\000\000\000\331\331\331/\331\331\333\216\333\333\333\061\331\331\334_\331\332\333"
  "\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331"
  "\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333"
  "\377\331\332\333\377\331\332\333\377\331\333\333]\333\333\333\061\331\331"
  "\333\216\331\331\331/\000\000\000\000\332\332\332E\332\332\334\202\333\333\333\007"
  "\000\000\000\000\000\000\000\000\333\333\333#\333\333\333\034\000\000\000\000\000\000\000\000\325\325\325"
  "\014\332\332\333\226\000\000\000\000\000\000\000\000\332\332\334t\331\332\333\374\331\332"
  "\333\377\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\377"
  "\331\332\333\377\331\332\333\377\331\332\333\377\331\332\333\374\331\331"
  "\333r\000\000\000\000\000\000\000\000\330\332\334\230\330\330\330\015\000\000\000\000\000\000\000\000\333"
  "\333\333\034\333\333\333#\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\331\331\333\242\277\277\277\004\000\000\000\000\000\000\000\000\331\331\331\066\332"
  "\332\333\270\331\332\333\376\331\332\333\377\331\332\333\377\331\332\333"
  "\377\331\332\333\377\331\332\333\376\331\333\333\266\331\331\335\065\000\000\000"
  "\000\000\000\000\000\377\377\377\003\331\332\334\237\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\331\333"
  "\333\233\322\341\341\021\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\334\334\334\026\333"
  "\333\333M\331\333\333j\331\333\333j\333\333\333M\333\333\333\025\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\322\341\341\021\331\333\333\233\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\330"
  "\333\333O\330\333\333V\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\330\333\333V\330\333\333O\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000",
};
