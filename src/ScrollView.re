open ReactNative;

[@bs.val] external alert : string => unit = "alert" ;

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
