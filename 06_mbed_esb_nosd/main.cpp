#include "mbed.h"

#include "nrf_esb.h"

#define APP_ERROR_CHECK(X)
#define VERIFY_SUCCESS(X)

DigitalOut  led_r(LED1);
DigitalOut  led_g(LED2);
DigitalOut  led_b(LED3);

void nrf_esb_event_handler(nrf_esb_evt_t const * p_event)
{
  led_r = 1;led_g = 1;led_b = 1;      
  //wait_ms(500);   
  led_r = 0;      
  //wait_ms(500);   
  led_g = 0;      
  //wait_ms(500);   
  led_b = 0;      
  //wait_ms(1000);  
  led_r = 1;led_g = 1;led_b = 1;      
  /*
    switch (p_event->evt_id)
    {
        case NRF_ESB_EVENT_TX_SUCCESS:
            NRF_LOG_DEBUG("TX SUCCESS EVENT\r\n");
            break;
        case NRF_ESB_EVENT_TX_FAILED:
            NRF_LOG_DEBUG("TX FAILED EVENT\r\n");
            break;
        case NRF_ESB_EVENT_RX_RECEIVED:
            NRF_LOG_DEBUG("RX RECEIVED EVENT\r\n");
            if (nrf_esb_read_rx_payload(&rx_payload) == NRF_SUCCESS)
            {
                // Set LEDs identical to the ones on the PTX.
                nrf_gpio_pin_write(LED_1, !(rx_payload.data[1]%8>0 && rx_payload.data[1]%8<=4));
                nrf_gpio_pin_write(LED_2, !(rx_payload.data[1]%8>1 && rx_payload.data[1]%8<=5));
                nrf_gpio_pin_write(LED_3, !(rx_payload.data[1]%8>2 && rx_payload.data[1]%8<=6));
                nrf_gpio_pin_write(LED_4, !(rx_payload.data[1]%8>3));

                NRF_LOG_DEBUG("Receiving packet: %02x\r\n", rx_payload.data[1]);
            }
            break;
    }
    */
}

uint32_t esb_init( void )
{
    uint32_t err_code;
    uint8_t base_addr_0[4] = {0xE7, 0xE7, 0xE7, 0xE7};
    uint8_t base_addr_1[4] = {0xC2, 0xC2, 0xC2, 0xC2};
    uint8_t addr_prefix[8] = {0xE7, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8 };
    nrf_esb_config_t nrf_esb_config         = NRF_ESB_DEFAULT_CONFIG;
    nrf_esb_config.payload_length           = 8;
    nrf_esb_config.protocol                 = NRF_ESB_PROTOCOL_ESB_DPL;
    nrf_esb_config.bitrate                  = NRF_ESB_BITRATE_2MBPS;
    nrf_esb_config.mode                     = NRF_ESB_MODE_PRX;
    nrf_esb_config.event_handler            = nrf_esb_event_handler;
    nrf_esb_config.selective_auto_ack       = false;

    err_code = nrf_esb_init(&nrf_esb_config);
    VERIFY_SUCCESS(err_code);

    err_code = nrf_esb_set_base_address_0(base_addr_0);
    VERIFY_SUCCESS(err_code);

    err_code = nrf_esb_set_base_address_1(base_addr_1);
    VERIFY_SUCCESS(err_code);

    err_code = nrf_esb_set_prefixes(addr_prefix, 8);
    VERIFY_SUCCESS(err_code);

    return err_code;
}


int main() 
{
  uint32_t err_code;

  led_r = 1;
  led_g = 1;
  led_b = 1;
  
  led_r = 0;
  //wait_ms(500);   
  led_r = 1;
  //wait_ms(1000);  

  err_code = esb_init();
  APP_ERROR_CHECK(err_code);

  while(1) 
  {
    led_g = 0;
    //wait_ms(500);   
    led_g = 1;
    //wait_ms(1000);  
  }
}
