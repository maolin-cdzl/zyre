/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
package org.zeromq.zyre;
import org.zeromq.czmq.*;

public class ZyreEvent implements AutoCloseable{
    static {
        try {
            System.loadLibrary ("zyrejni");
        }
        catch (Exception e) {
            System.exit (-1);
        }
    }
    public long self;
    /*
    Constructor: receive an event from the zyre node, wraps zyre_recv.
    The event may be a control message (ENTER, EXIT, JOIN, LEAVE) or  
    data (WHISPER, SHOUT).                                            
    */
    native static long __new (long node);
    public ZyreEvent (Zyre node) {
        /*  TODO: if __new fails, self is null...  */
        self = __new (node.self);
    }
    public ZyreEvent (long pointer) {
        self = pointer;
    }
    public ZyreEvent () {
        self = 0;
    }
    /*
    Destructor; destroys an event instance
    */
    native static void __destroy (long self);
    @Override
    public void close () {
        __destroy (self);
        self = 0;
    }
    /*
    Returns event type, which is a zyre_event_type_t
    */
    native static int __type (long self);
    public int type () {
        return __type (self);
    }
    /*
    Return the sending peer's id as a string
    */
    native static String __sender (long self);
    public String sender () {
        return __sender (self);
    }
    /*
    Return the sending peer's public name as a string
    */
    native static String __name (long self);
    public String name () {
        return __name (self);
    }
    /*
    Return the sending peer's ipaddress as a string
    */
    native static String __address (long self);
    public String address () {
        return __address (self);
    }
    /*
    Returns the event headers, or NULL if there are none
    */
    native static long __headers (long self);
    public Zhash headers () {
        return new Zhash (__headers (self));
    }
    /*
    Returns value of a header from the message headers   
    obtained by ENTER. Return NULL if no value was found.
    */
    native static String __header (long self, String name);
    public String header (String name) {
        return __header (self, name);
    }
    /*
    Returns the group name that a SHOUT event was sent to
    */
    native static String __group (long self);
    public String group () {
        return __group (self);
    }
    /*
    Returns the incoming message payload (currently one frame)
    */
    native static long __msg (long self);
    public Zmsg msg () {
        return new Zmsg (__msg (self));
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public void test (boolean verbose) {
        __test (verbose);
    }
}
