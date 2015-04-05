/*  emnr.h

This file is part of a program that implements a Software-Defined Radio.

Copyright (C) 2015 Warren Pratt, NR0V

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

The author can be reached by email at  

warren@wpratt.com

*/

#ifndef _emnr_h
#define _emnr_h

typedef struct _emnr
{
	int run;
	int position;
	int bsize;
	float* in;
	float* out;
	int fsize;
	int ovrlp;
	int incr;
	float* window;
	int iasize;
	float* inaccum;
	float* forfftin;
	float* forfftout;
	int msize;
	float* mask;
	float* revfftin;
	float* revfftout;
	float** save;
	int oasize;
	float* outaccum;
	float rate;
	int wintype;
	float gain;
	int nsamps;
	int iainidx;
	int iaoutidx;
	int init_oainidx;
	int oainidx;
	int oaoutidx;
	int saveidx;
	fftwf_plan Rfor;
	fftwf_plan Rrev;
	struct _g
	{
		int gain_method;
		int npe_method;
		int ae_run;
		float msize;
		float* mask;
		float* y;
		float* lambda_y;
		float* lambda_d;
		float* prev_mask;
		float* prev_gamma;
		float gf1p5;
		float alpha;
		float eps_floor;
		float gamma_max;
		float q;
	} g;
	struct _npest
	{
		int incr;
		float rate;
		int msize;
		float* lambda_y;
		float* lambda_d;
		float* p;
		float* alphaOptHat;
		float alphaC;
		float alphaCsmooth;
		float alphaCmin;
		float* alphaHat;
		float alphaMax;
		float* sigma2N;
		float alphaMin_max_value;
		float snrq;
		float betamax;
		float* pbar;
		float* p2bar;
		float invQeqMax;
		float av;
		float* Qeq;
		int U;
		float Dtime;
		int V;
		int D;
		float MofD;
		float MofV;
		float* bmin;
		float* bmin_sub;
		int* k_mod;
		float* actmin;
		float* actmin_sub;
		int subwc;
		int* lmin_flag;
		float* pmin_u;
		float invQbar_points[4];
		float nsmax[4];
		float** actminbuff;
		int amb_idx;
	} np;
	struct _npests
	{
		int incr;
		float rate;
		int msize;
		float* lambda_y;
		float* lambda_d;
		
		float alpha_pow;
		float alpha_Pbar;
		float epsH1;
		float epsH1r;

		float* sigma2N;
		float* PH1y;
		float* Pbar;
		float* EN2y;
	} nps;
	struct _ae
	{
		int msize;
		float* lambda_y;
		float zetaThresh;
		float psi;
		float* nmask;
	} ae;
}emnr, *EMNR;

extern EMNR create_emnr (int run, int position, int size, float* in, float* out, int fsize, int ovrlp, 
	int rate, int wintype, float gain, int gain_method, int npe_method, int ae_run);

extern void destroy_emnr (EMNR a);

extern void flush_emnr (EMNR a);

extern void xemnr (EMNR a, int pos);

#endif