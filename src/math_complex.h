/* ----------------------------------------------------------------------
    This is the

    ██╗     ██╗ ██████╗  ██████╗  ██████╗ ██╗  ██╗████████╗███████╗
    ██║     ██║██╔════╝ ██╔════╝ ██╔════╝ ██║  ██║╚══██╔══╝██╔════╝
    ██║     ██║██║  ███╗██║  ███╗██║  ███╗███████║   ██║   ███████╗
    ██║     ██║██║   ██║██║   ██║██║   ██║██╔══██║   ██║   ╚════██║
    ███████╗██║╚██████╔╝╚██████╔╝╚██████╔╝██║  ██║   ██║   ███████║
    ╚══════╝╚═╝ ╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝®

    DEM simulation engine, released by
    DCS Computing Gmbh, Linz, Austria
    http://www.dcs-computing.com, office@dcs-computing.com

    LIGGGHTS® is part of CFDEM®project:
    http://www.liggghts.com | http://www.cfdem.com

    Core developer and main author:
    Christoph Kloss, christoph.kloss@dcs-computing.com

    LIGGGHTS® is open-source, distributed under the terms of the GNU Public
    License, version 2 or later. It is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. You should have
    received a copy of the GNU General Public License along with LIGGGHTS®.
    If not, see http://www.gnu.org/licenses . See also top-level README
    and LICENSE files.

    LIGGGHTS® and CFDEM® are registered trade marks of DCS Computing GmbH,
    the producer of the LIGGGHTS® software and the CFDEM®coupling software
    See http://www.cfdem.com/terms-trademark-policy for details.

-------------------------------------------------------------------------
    Contributing author and copyright for this file:
    This file is from LAMMPS
    LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
    http://lammps.sandia.gov, Sandia National Laboratories
    Steve Plimpton, sjplimp@sandia.gov

    Copyright (2003) Sandia Corporation.  Under the terms of Contract
    DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
    certain rights in this software.  This software is distributed under
    the GNU General Public License.
------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Contributing author: Pieter J. in 't Veld (SNL)
------------------------------------------------------------------------- */

#ifndef LMP_MATH_COMPLEX_H
#define LMP_MATH_COMPLEX_H

#define COMPLEX_NULL        {0, 0}

namespace LAMMPS_NS {

typedef struct complex {
  double re, im; } complex;

}

#define C_MULT(d, x, y) { \
  d.re = x.re*y.re-x.im*y.im; \
  d.im = x.re*y.im+x.im*y.re; }

#define C_RMULT(d, x, y) { \
  complex t = x; \
  d.re = t.re*y.re-t.im*y.im; \
  d.im = t.re*y.im+t.im*y.re; }

#define C_CRMULT(d, x, y) { \
  complex t = x; \
  d.re = t.re*y.re-t.im*y.im; \
  d.im = -t.re*y.im-t.im*y.re; }

#define C_SMULT(d, x, y) { \
  d.re = x.re*y; \
  d.im = x.im*y; }

#define C_ADD(d, x, y) { \
  d.re = x.re+y.re; \
  d.im = x.im+y.im; }

#define C_SUBTR(d, x, y) { \
  d.re = x.re-y.re; \
  d.im = x.im-y.im; }

#define C_CONJ(d, x) { \
  d.re = x.re; \
  d.im = -x.im; }

#define C_SET(d, x, y) { \
  d.re = x; \
  d.im = y; }

#define C_ANGLE(d, angle) { \
  double a = angle; \
  d.re = cos(a); \
  d.im = sin(a); }

#define C_COPY(d, x) { \
  memcpy(&d, &x, sizeof(complex)); }

#endif
