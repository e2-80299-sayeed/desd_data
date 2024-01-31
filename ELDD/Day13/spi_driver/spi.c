#include <linux/init.h>
#include <linux/module.h>
#include <linux/spi/spi.h>
#include <linux/delay.h>

static struct spi_device *my_spi_device;

struct spi_board_info my_spi_device_info = 
{
  .modalias     = "my-spi-driver",
  .max_speed_hz = 4000000,              // speed your device (slave) can handle
  .bus_num      = SPI_BUS_NUM,          // SPI 1
  .chip_select  = 0,                    // Use 0 Chip select (GPIO 18)
  .mode         = SPI_MODE_0            // SPI mode 0
};

int my_spi_write( uint8_t data )
{
  int     ret = -1;
  uint8_t rx  = 0x00;
  
  if( my_spi_device )
  {    
    struct spi_transfer  tr = 
    {
      .tx_buf  = &data,
      .rx_buf = &rx,
      .len    = 1,
    };

    spi_sync_transfer( my_spi_device, &tr, 1 );
  }
  
  //pr_info("Received = 0x%02X \n", rx);
  
  return( ret );
}

static int __init my_spi_init(void)
{
  int     ret;
  struct  spi_master *master;
  
  master = spi_busnum_to_master( my_spi_device_info.bus_num );
  if( master == NULL )
  {
    pr_err("SPI Master not found.\n");
    return -ENODEV;
  }
   
  // create a new slave device, given the master and device info
  my_spi_device = spi_new_device( master, &my_spi_device_info );
  if( my_spi_device == NULL ) 
  {
    pr_err("FAILED to create slave.\n");
    return -ENODEV;
  }
  
  // 8-bits in a word
  my_spi_device->bits_per_word = 8;

  // setup the SPI slave device
  ret = spi_setup( my_spi_device );
  if( ret )
  {
    pr_err("FAILED to setup slave.\n");
    spi_unregister_device( my_spi_device );
    return -ENODEV;
  }
  
  //initialize the device -- in init() or probe()
  
  pr_info("SPI driver Registered\n");
  return 0;
}

static void __exit my_spi_exit(void)
{ 
  if( my_spi_device )
  {
    // deinitialize the device
    spi_unregister_device( my_spi_device );    // Unregister the SPI slave
    pr_info("SPI driver Unregistered\n");
  }
}
 
module_init(my_spi_init);
module_exit(my_spi_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("");
MODULE_DESCRIPTION("A simple device driver - SPI Slave Protocol Driver");

