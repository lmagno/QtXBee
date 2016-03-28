#ifndef XBEEPACKET_H
#define XBEEPACKET_H

#include <QByteArray>

class XBeePacket
{
public:

	/// @brief Values for API frame types.
	///  	   Requests are less than 0x80 and responses are more than 0x80.
	///
	enum FrameType {
		ATCommand 						= 0x08,
		ATCommandQueue 					= 0x09,
		TXRequest 						= 0x10,
		TXRequestExplicit 				= 0x11,
		ATCommandRemote 				= 0x17,
		ATCommandResponse 				= 0x88,
		ModemStatus 					= 0x8A,
		TransmitStatus 					= 0x8B,
		RXIndicator 					= 0x90,
		RXIndicatorExplicit 			= 0x91,
		NodeIdentificationIndicator 	= 0x95,
		ATCommandResponseRemote 		= 0x97
	};

	virtual uint8_t	   getFrameType() const = 0;
	virtual QByteArray getFrameData() = 0;
	virtual void	   setFrameData(QByteArray data) = 0;
	virtual			   ~XBeePacket() {} // Magic

	/// @brief Overload of int() so one can use this object directly
	///   	   in switch statements about the frame type.
	///
	/// Example:
	/// @code
	/// switch(packet)
	/// {
	/// 		case XBeePacket::ATCommandResponse:
	///   			...
	/// 			break;
	///  		case XBeePacket::ATCommandQueue:
	/// 			...
	/// 			break;
	///			case XBeePacket::TXRequest:
	/// 			...
	/// 			break;
	///
	/// 		⋮
	///
	///			default:
	///				...
 	/// }
	/// @endcode
	virtual operator int() {return getFrameType();}
};

#endif // XBEEPACKET_H
