/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "QmlZyreEvent.h"


///
//  Returns event type, which is a zyre_event_type_t
zyre_event_type_t QmlZyreEvent::type () {
    return zyre_event_type (self);
};

///
//  Return the sending peer's id as a string
const QString QmlZyreEvent::sender () {
    return QString (zyre_event_sender (self));
};

///
//  Return the sending peer's public name as a string
const QString QmlZyreEvent::name () {
    return QString (zyre_event_name (self));
};

///
//  Return the sending peer's ipaddress as a string
const QString QmlZyreEvent::address () {
    return QString (zyre_event_address (self));
};

///
//  Returns the event headers, or NULL if there are none
zhash_t *QmlZyreEvent::headers () {
    return zyre_event_headers (self);
};

///
//  Returns value of a header from the message headers   
//  obtained by ENTER. Return NULL if no value was found.
const QString QmlZyreEvent::header (const QString &name) {
    return QString (zyre_event_header (self, name.toUtf8().data()));
};

///
//  Returns the group name that a SHOUT event was sent to
const QString QmlZyreEvent::group () {
    return QString (zyre_event_group (self));
};

///
//  Returns the incoming message payload (currently one frame)
zmsg_t *QmlZyreEvent::msg () {
    return zyre_event_msg (self);
};


QObject* QmlZyreEvent::qmlAttachedProperties(QObject* object) {
    return new QmlZyreEventAttached(object);
}


///
//  Self test of this class.
void QmlZyreEventAttached::test (bool verbose) {
    zyre_event_test (verbose);
};

///
//  Constructor: receive an event from the zyre node, wraps zyre_recv.
//  The event may be a control message (ENTER, EXIT, JOIN, LEAVE) or  
//  data (WHISPER, SHOUT).                                            
QmlZyreEvent *QmlZyreEventAttached::construct (QmlZyre *node) {
    QmlZyreEvent *qmlSelf = new QmlZyreEvent ();
    qmlSelf->self = zyre_event_new (node->self);
    return qmlSelf;
};

///
//  Destructor; destroys an event instance
void QmlZyreEventAttached::destruct (QmlZyreEvent *qmlSelf) {
    zyre_event_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
