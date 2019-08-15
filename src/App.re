open ReactNative;

[@bs.val] external alert : string => unit = "alert" ;

let styles = Style.(StyleSheet.create({
    "container": style(~paddingTop=dp(60.), ~alignItems=`center, ()),
    "button": style(~marginBottom=dp(30.), ~width=dp(260.), ~alignItems=`center, ~backgroundColor="#2196F3", ()),
    "buttonText": style(~textAlign=`center, ~padding=dp(20.), ~color="white", ()),
}));

module ReactTinyLogo = {
    [@react.component]
    let make = () => {
         //let uri = "https://facebook.github.io/react-native/img/tiny_logo.png";
         let uri = "https://upload.wikimedia.org/wikipedia/commons/d/de/Bananavarieties.jpg";
         let source = Image.Source.fromUriSource(Image.uriSource(~uri, ~width=64., ~height=64., ())); 
        <Image source/>
    }
}

module IScrolledDownAndWhatHappenedNextShockedMe = {
    [@react.component]
    let make = () => {
        <ScrollView>
            <Text style=Style.(style(~fontSize=96., ()))>{React.string("Scroll me plz")}</Text>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <Text style=Style.(style(~fontSize=96., ()))>{React.string("If you like")}</Text>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <Text style=Style.(style(~fontSize=96., ()))>{React.string("Scrolling down")}</Text>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <Text style=Style.(style(~fontSize=96., ()))>{React.string("What's the best")}</Text>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <Text style=Style.(style(~fontSize=96., ()))>{React.string("Framework around?")}</Text>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <Text style=Style.(style(~fontSize=96., ()))>{React.string("React Native")}</Text>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <ReactTinyLogo/>
            <Text style=Style.(style(~fontSize=96., ()))>{React.string("But with ReasonML")}</Text>
        </ScrollView>
    }
}

[@react.component]
let app = () => {
        <IScrolledDownAndWhatHappenedNextShockedMe/>
};
