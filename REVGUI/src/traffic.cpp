#include "traffic.h"

traffic::traffic() : QObject()
{


}

void traffic::init() {

    //set application OAuth keys
    twitterObj.getOAuth().setConsumerKey( std::string( "xHaOQn5lDa1tkLc8lnNpuQ" ) );
    twitterObj.getOAuth().setConsumerSecret( std::string( "DahAMvPdakTPlf6uyOJRWrqLVKCPZW0HPmw5Wu5Gbo" ) );

    /* Step 1: Check if we alredy have OAuth access token from a previous run */

    char szKey[1024];
     std::string myOAuthAccessTokenKey("");
     std::string myOAuthAccessTokenSecret("");
     std::ifstream oAuthTokenKeyIn;
     std::ifstream oAuthTokenSecretIn;

     oAuthTokenKeyIn.open( "twitterClient_token_key.txt" );
     oAuthTokenSecretIn.open( "twitterClient_token_secret.txt" );

     memset( szKey, 0, 1024 );
     oAuthTokenKeyIn >> szKey;
     myOAuthAccessTokenKey = szKey;

     memset( szKey, 0, 1024 );
     oAuthTokenSecretIn >> szKey;
     myOAuthAccessTokenSecret = szKey;

     oAuthTokenKeyIn.close();
     oAuthTokenSecretIn.close();

     if( myOAuthAccessTokenKey.size() && myOAuthAccessTokenSecret.size() )
     {
         /* If we already have these keys, then no need to go through auth again */
         //printf( "\nUsing:\nKey: %s\nSecret: %s\n\n", myOAuthAccessTokenKey.c_str(), myOAuthAccessTokenSecret.c_str() );
         emit debugMsg(QtDebugMsg,"[Traffic]", "Access keys available");
         twitterObj.getOAuth().setOAuthTokenKey( myOAuthAccessTokenKey );
         twitterObj.getOAuth().setOAuthTokenSecret( myOAuthAccessTokenSecret );
     }
     else
     {
         //emit debugMsg(QtDebugMsg,"[Traffic]", "No Access keys available");
        /*
         // Step 2: Get request token key and secret
         twitterObj.oAuthRequestToken( tmpStr );

         // Step 3: Ask user to visit web link and get PIN
         char szOAuthVerifierPin[1024];
         memset( szOAuthVerifierPin, 0, 1024 );
         printf( "\nPlease visit this link in web browser and authorize this application:\n%s", tmpStr.c_str() );
         printf( "\nEnter the PIN provided by twitter: " );
         gets( szOAuthVerifierPin );
         tmpStr = szOAuthVerifierPin;
         twitterObj.getOAuth().setOAuthPin( tmpStr );

         // Step 4: Exchange request token with access token
         twitterObj.oAuthAccessToken();

         // Step 5: Now, save this access token key and secret for future use without PIN
         twitterObj.getOAuth().getOAuthTokenKey( myOAuthAccessTokenKey );
         twitterObj.getOAuth().getOAuthTokenSecret( myOAuthAccessTokenSecret );

         // Step 6: Save these keys in a file or wherever
                 std::ofstream oAuthTokenKeyOut;
                 std::ofstream oAuthTokenSecretOut;

         oAuthTokenKeyOut.open( "twitterClient_token_key.txt" );
         oAuthTokenSecretOut.open( "twitterClient_token_secret.txt" );

         oAuthTokenKeyOut.clear();
         oAuthTokenSecretOut.clear();

         oAuthTokenKeyOut << myOAuthAccessTokenKey.c_str();
         oAuthTokenSecretOut << myOAuthAccessTokenSecret.c_str();

         oAuthTokenKeyOut.close();
         oAuthTokenSecretOut.close();
         */
     }
}

QDomNodeList traffic::status() {

    // retrieve main roads twitter information
    twitterObj.timelineUserGet( "74385014", true );

    twitterObj.getLastWebResponse( replyMsg );
    //printf( "\ntwitterClient:: twitCurl::timelinePublicGet web response:\n%s\n", replyMsg.c_str() );

    QString xmlText = QString::fromStdString(replyMsg.c_str());
    //qDebug() << xmlText;

   // emit debugMsg(QtDebugMsg,"Traffic", xmlText);

    QDomDocument doc;
    doc.setContent(xmlText);
    QDomNodeList list=doc.elementsByTagName("status");

   // for(int i = 0; i < list.size(); i++) {
   //     QString status=list.at(i).toElement().text();
   // }

    return list;
}

QDomNodeList traffic::date() {

    twitterObj.getLastWebResponse( replyMsg );

    QString xmlText = QString::fromStdString(replyMsg.c_str());
    //qDebug() << xmlText;

    QDomDocument doc;
    doc.setContent(xmlText);
    QDomNodeList list=doc.elementsByTagName("created_at");

   // for(int i = 0; i < list.size(); i++) {
   //     QString status=list.at(i).toElement().text();
   // }

    return list;
}
