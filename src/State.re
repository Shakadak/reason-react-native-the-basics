open ReactNative;

module Blink = {
    [@react.component]
    let make = (~text) => {
        let (isShowingText, onChange) = React.useState(() => true);
        React.useEffect0(() => {
            let timerId = Js.Global.setInterval(() => onChange((!)), 1000);
            Some(() => Js.Global.clearInterval(timerId))
        });

        if (!isShowingText) {
            React.null
        } else {
            <Text>{React.string(text)}</Text>
        }
    };
}

[@react.component]
let make = () => {
    <View>
        <Blink text="I love to blink" />
        <Blink text="Yes blinking is so great" />
        <Blink text="Why did they ever take this out of HTML" />
        <Blink text="Look at me look at me look at me" />
    </View>
};
