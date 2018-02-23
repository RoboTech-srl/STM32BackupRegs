#ifndef __STM32_BACKUP_H
#define __STM32_BACKUP_H

#include "Arduino.h"

// Check if RTC HAL enable in variants/board_name/stm32yzxx_hal_conf.h
#if !defined(HAL_RTC_MODULE_ENABLED)
#error "RTC configuration is missing. Check flag HAL_RTC_MODULE_ENABLED in variants/board_name/stm32yzxx_hal_conf.h"
#endif

class STM32Backup
{
public:
  enum { REGISTER_COUNT = RTC_BKP_NUMBER };
  
  STM32Backup() {}
  
  void setRegister(uint32_t index, uint32_t value)
  {
#if defined(STM32F1xx)
    LL_RTC_BKP_SetRegister(BKP, index, value);
#else
    LL_RTC_BAK_SetRegister(RTC, index, value);
#endif
  }
  uint32_t getRegister(uint32_t index)
  {
#if defined(STM32F1xx)
    return LL_RTC_BKP_GetRegister(BKP, index);
#else
    return LL_RTC_BAK_GetRegister(RTC, index);
#endif
  }
};

#endif /* __STM32_BACKUP_H */
