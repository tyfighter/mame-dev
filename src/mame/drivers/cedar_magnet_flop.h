// license:BSD-3-Clause
// copyright-holders:David Haywood

#pragma once

#ifndef CEDAR_MAGNET_FLOP_DEF
#define CEDAR_MAGNET_FLOP_DEF

extern const device_type CEDAR_MAGNET_FLOP;

#define MCFG_CEDAR_MAGNET_FLOP_ADD(_tag) \
	MCFG_DEVICE_ADD(_tag, CEDAR_MAGNET_FLOP, 0)

#include "machine/nvram.h"

class cedar_magnet_flop_device :  public device_t
{
public:
	// construction/destruction
	cedar_magnet_flop_device(const machine_config &mconfig, const char *tag, device_t *owner, UINT32 clock);

	UINT8 m_flopdat;
	UINT8 m_flopcmd;
	UINT8 m_flopsec;
	UINT8 m_flopstat;
	UINT8 m_floptrk;

	UINT8 m_curtrack;
	int m_secoffs;

	DECLARE_READ8_MEMBER(port60_r);
	DECLARE_READ8_MEMBER(port61_r);
	DECLARE_READ8_MEMBER(port63_r);

	DECLARE_WRITE8_MEMBER(port60_w);
	DECLARE_WRITE8_MEMBER(port62_w);
	DECLARE_WRITE8_MEMBER(port63_w);

	DECLARE_READ8_MEMBER(read);
	DECLARE_WRITE8_MEMBER(write);

protected:
	virtual machine_config_constructor device_mconfig_additions() const override;
	virtual void device_start() override;
	virtual void device_reset() override;
private:
};

#endif
