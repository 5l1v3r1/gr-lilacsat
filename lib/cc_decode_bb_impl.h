/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_LILACSAT_CC_DECODE_BB_IMPL_H
#define INCLUDED_LILACSAT_CC_DECODE_BB_IMPL_H

#include <lilacsat/cc_decode_bb.h>

extern "C"
{
    #include "kiss/kiss.h"
}

#define	LENTH_BUF_SYNC_OUT	1024

namespace gr {
  namespace lilacsat {

    class cc_decode_bb_impl : public cc_decode_bb
    {
     private:
	  pmt::pmt_t	d_out_port;

	  uint8_t		d_rx_bit_state;
	  uint8_t		d_mask_bit_out;
	  uint8_t		d_syncing;
      uint32_t		d_buffer_sync_det;
	  uint8_t		d_n_out;
	  uint8_t		d_buf_sync_out[LENTH_BUF_SYNC_OUT];

	  Kiss			d_ki;

      static void	kiss_msg_callback(void *obj_ptr, char *ptr, uint16_t len);

     public:
      cc_decode_bb_impl();
      ~cc_decode_bb_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace lilacsat
} // namespace gr

#endif /* INCLUDED_LILACSAT_CC_DECODE_BB_IMPL_H */

