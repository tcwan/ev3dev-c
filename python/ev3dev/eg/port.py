# -*- coding: utf-8 -*-

import sys
from ev3dev import *

if __name__ == '__main__':
    print 'Waiting the EV3 brick online...'
    if ev3_init() < 1: sys.exit( 1 )

    print '*** ( EV3 ) Hello! ***'
    ev3_port_init()

    print 'Found ports:'
    for i in range( PORT_DESC__LIMIT_ ):
        type_inx = ev3_port_desc_type_inx( i )
        if type_inx != PORT_TYPE__NONE_:
            print '  type =', ev3_port_type( type_inx )
            print '  port =', ev3_port_name( ev3_port_desc_port( i ), ev3_port_desc_extport( i ))
            ok, mode = get_port_mode( i, 256 )
            if ok:
                print '  mode =', mode

    sn = ev3_search_port( INPUT_2, EXT_PORT__NONE_ )
    ok, s = get_port_modes( sn, 256 )
    if ok:
        print 'Port %s modes: %s' % ( ev3_port_name( INPUT_2, EXT_PORT__NONE_ ), s )

    ev3_uninit()
